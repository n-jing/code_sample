
int KKT_range_based(double* solution){
  c_.setZero();//WARNING!!!!! constraint_ must suit for displacement
  
  SparseMatrix<double, ColMajor> trans_J = J_.transpose();
  MatrixXd lhs_lam = J_ * llt_->solve(trans_J);
  ASSERT(llt_->info() == Success);
  VectorXd rhs_lam = J_ * llt_->solve(b_) - c_;
  ASSERT(llt_->info() == Success);

  LLT<MatrixXd> lam_slv(lhs_lam);
  // CholmodSupernodalLLT<decltype(lhs_lam)> lam_slv(lhs_lam);
  ASSERT(lam_slv.info() == Success);
  VectorXd lam = lam_slv.solve(rhs_lam);
  ghost_force_ = VectorXd(trans_J * lam);
  //solve x
  Map<VectorXd> solu(solution, A_.rows());
  solu = llt_->solve(b_ - J_.transpose() * lam);
  return 0;
}

int KKT_direct(double* solution ){
  const size_t dof = A_.rows(), num_cons = J_.rows(), num_all = dof + num_cons;
  
  SparseMatrix<double> whole_mat(num_all, num_all);{
    vector<Triplet<double>> trips;
    for (int k=0; k<A_.outerSize(); ++k)
      for (decltype(A_)::InnerIterator it(A_,k); it; ++it)
        trips.push_back(Triplet<double>(it.row(), it.col(), it.value()));
    
    for (int k=0; k<J_.outerSize(); ++k)
      for (decltype(J_)::InnerIterator it(J_,k); it; ++it){
        trips.push_back(Triplet<double>(it.row() + dof, it.col(), it.value()));
        trips.push_back(Triplet<double>(it.col(), it.row() + dof, it.value()));
      }
    whole_mat.reserve(trips.size());
    whole_mat.setFromTriplets(trips.begin(), trips.end());
  }


  SparseQR<decltype(whole_mat), COLAMDOrdering<int>> slv(whole_mat);

  VectorXd rhs(num_all);{
    rhs.topRows(dof) = b_;
    rhs.bottomRows(num_cons) = c_;
  }
  
  VectorXd solu_all = slv.solve(rhs);
  Map<VectorXd> solu(solution, dof);
  solu = solu_all.topRows(dof);
  VectorXd lambda = solu_all.bottomRows(num_cons);

  ghost_force_ = J_.transpose() * lambda;
  return 0;
}

int KKT_nullspace(double * solution) {
  const size_t dof = A_.rows();
  SPQR<decltype(J_)> qr_solver;
  qr_solver.setPivotThreshold(1e-3);
  qr_solver.compute(J_);
  const size_t ker_dim = J_.cols()-qr_solver.rank();
  cout << "kernel dimension is " << ker_dim << endl;
  SparseMatrix<double> KER;{
    qr_solver.compute(J_.transpose());
    const MatrixXd Id = MatrixXd::Identity(J_.cols(), J_.cols());
    MatrixXd denseQ = qr_solver.matrixQ()*Id;
    denseQ = denseQ.topRightCorner(denseQ.rows(), ker_dim).eval();
    vector<Triplet<double>> trips;
    for (size_t i = 0; i < denseQ.rows(); ++i) {
      for (size_t j = 0; j < denseQ.cols(); ++j) {
        if ( fabs(denseQ(i, j)) >= 1e-8 )
          trips.push_back(Triplet<double>(i, j, denseQ(i, j)));
      }
    }
    KER.resize(denseQ.rows(), denseQ.cols());
    KER.reserve(trips.size());
    KER.setFromTriplets(trips.begin(), trips.end());
  }
  const VectorXd tmp = VectorXd::Random(ker_dim);
  cout << "\t@test general solution: " << (J_*(KER*tmp)).norm() << endl;

  SparseMatrix<double> LHS(ker_dim, ker_dim);{
    LHS = KER.transpose() * A_ * KER;
  }

  VectorXd rhs = VectorXd::Zero(ker_dim);
  rhs = KER.transpose() * b_;

  CholmodSupernodalLLT<decltype(LHS)> slv(LHS);
  VectorXd q = slv.solve(rhs);
  Map<VectorXd> solu(solution, dof);
  solu = KER * q;
  ghost_force_ = b_ - A_ * solu;
  
  return 0;
}
