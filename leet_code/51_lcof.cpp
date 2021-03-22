#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


using namespace std;


class Solution {
public:
    int reversePairs(vector<int>& nums) {
      vector<int> sort_nums(nums.size());
      const int N = nums.size();
      int count = 0;
      countreversePairs(0, N, nums, sort_nums, count);
      return count;
    }
  int countreversePairs(int l, int r, vector<int> &nums, vector<int> &sort_nums, int &count)
    {
      if (r == l+1)
        return 0;
      int m = (l+r) / 2;
      countreversePairs(l, m, nums, sort_nums, count);
      countreversePairs(m, r, nums, sort_nums, count);
      int li = l;
      int ri = m;
      int i = l;
      while (li < m || ri < r)
      {
        if (li < m && ri < r && nums[li] <= nums[ri])
        {
          sort_nums[i++] = nums[li++];
        }
        else if (li < m && ri < r && nums[li] > nums[ri])
        {
          sort_nums[i++] = nums[ri++];
          count += (m-li);
        }
        else if (li < m && ri == r)
        {
          sort_nums[i++] = nums[li++];
        }
        else
        {
          sort_nums[i++] = nums[ri++];
          count += (m-li);
        }
      }
      for (int k = l; k < r; ++k)
      {
        nums[k] = sort_nums[k];
      }
      return 0;
    }
  
};


#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  vector<int> vec = {7, 5, 6, 4};
  Solution su;
  auto p = su.reversePairs(vec);
  cerr << "res:" << p << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
