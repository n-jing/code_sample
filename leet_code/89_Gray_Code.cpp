class Solution {
public:
    vector<int> grayCode(int n) {
      const int N = pow(2, n);
      int d = 1;
      int s = 1;
      vector<int> code(N, 0);
      for (int i = 1; i <= n; ++i)
      {
        for (int j = 0; j < d; ++j)
        {
          code[s+j] = code[s-1-j] + d;
        }
        s *= 2;
        d *= 2;
      }
      return code;
    }
};
