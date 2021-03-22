#include <vector>
#include <iostream>
#include <numeric>
#include <limits>
#include <algorithm>


using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
      vector<vector<int>> count(n, vector<int>(n, 0));

      for (int i = 1; i < n; ++i)
      {
        for (int r = 0; r < n; ++r)
        {
          if (r+i >= n)
            continue;
          vector<int> c(i+1);
          for (int j = 0; j <= i; ++j)
          {
            int l = 0;
            if (j > 0)
              l = count[r][r+j-1];
            int rr = 0;
            if (j < i)
              rr = count[r+j+1][r+i];
            c[j] = r+j+1 + max(l, rr);
          }
          count[r][r+i] = *min_element(c.begin(), c.end());
        }
      }

      return count[0][n-1];
    }
};


int main (int argc, char *argv[])
{
  Solution su;
  int p = su.getMoneyAmount(10);
  cerr << p << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
