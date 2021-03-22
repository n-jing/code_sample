#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
      if (A.size() <= 1)
        return 0;

      const int N = A.size();
      long long sum = 0;
      long long count = 0;
      for (int i = 0; i < N; ++i)
      {
        count += i*A[i];
        sum += A[i];
      }

      vector<long long> diff(N, count);
      for (int n = 1; n < N; ++n)
      {
        diff[n] = diff[n-1] + sum - (long long)N * (long long)A[N-n];
      }
      
      return *max_element(diff.begin(), diff.end());
    }
};

int main (int argc, char *argv[])
{
  Solution su;
  vector<int> vec = {4, 3, 2, 6};
  int p = su.maxRotateFunction(vec);
  cerr << p << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
