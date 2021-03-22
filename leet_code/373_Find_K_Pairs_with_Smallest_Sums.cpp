#include <vector>
#include <iostream>
#include <numeric>
#include <limits>


using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      const int N = nums1.size();
      const int M = nums2.size();
      k = min(k, M*N);
      vector<vector<int>> res(k);
      vector<int> connect(M, 0);
      for (int ki = 0; ki < k; ++ki)
      {
        int idx = 0;
        int sum = numeric_limits<int>::max();
        for (int r = 0; r < M; ++r)
        {
          if (connect[r] < N && nums1[connect[r]] + nums2[r] < sum)
          {
            idx = r;
            sum = nums1[connect[r]] + nums2[r];
          }
        }
        res[ki] = {nums1[connect[idx]], nums2[idx]};
        connect[idx]++;
      }

      return res;
    }
};

int main (int argc, char *argv[])
{
  Solution su;
  vector<int> v1 = {1, 7, 11};
  vector<int> v2 = {2, 4, 6};
  auto p = su.kSmallestPairs(v1, v2, 10);
  for (auto &v : p)
  {
    cerr << v[0] << " " << v[1] << endl;
  }

  cerr << "Hello World!" << endl;
  return 0;
}
