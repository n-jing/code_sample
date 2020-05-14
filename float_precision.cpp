//g++ -o flt main.cpp -I/usr/local/include -L/usr/local/lib -lgmpxx -lgmp


# include <iostream>
# include <iomanip>
#include <gmp.h>

using namespace std;

int main ( int argc, char *argv[] )
{
  array<double, 2> input_number = {
    -0.000000000000000000000002100000000122,
    -1.0};

  // array<double, 2> input_number = {1.1e-24, 1.1};
  array<mpq_t, 2> rat_number;
  array<mpf_t, 2> float_number;
    
  for (size_t i = 0; i < 2; ++i)
  {
    mpq_init(rat_number[i]);
    mpq_set_d(rat_number[i], input_number[i]);

    mpf_init2(float_number[i], 64);
    mpf_set_d(float_number[i], input_number[i]);
  }

  mpq_t rat_ret;
  mpq_init(rat_ret);
  mpq_add(rat_ret, rat_number[0], rat_number[1]);

  mpf_t float_ret;
  mpf_init2(float_ret, 65);
  mpf_add(float_ret, float_number[0], float_number[1]);

  mpq_t rat_flt;
  mpq_init(rat_flt);
  mpq_set_f(rat_flt, float_ret);

    
  if (mpf_get_prec(float_ret) != 64 ||
      mpf_get_prec(float_number[0]) != 64 || mpf_get_prec(float_number[1]) != 64)
  {
    cerr << "warning" << endl;
  }

  if (!mpq_equal(rat_ret, rat_flt))
  {
    cerr << setprecision(10000) << "rational:" << mpq_get_d(rat_ret) << endl << "high precision float:" << mpf_get_d(float_ret) << endl << "high precision float ration:" << mpq_get_d(rat_flt) << endl;
    cerr << "error:high precision floating-point is not equal with ration" << endl << "input n1:" << input_number[0] << endl << "input n2:" << input_number[1] << endl;
    exit(1);
  }

  for (size_t i = 0; i < 2; ++i)
  {
    mpf_clear(float_number[i]);
    mpq_clear(rat_number[i]);
  }
  mpf_clear(float_ret);
  mpq_clear(rat_ret);
  mpq_clear(rat_flt);


  return 0;
}

