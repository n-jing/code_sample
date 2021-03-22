#include <random>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;


class Solution {
public:
    Solution(vector<int>& nums) {
      num_ = nums;
      idx_ = vector<int>(nums.size());
      iota(idx_.begin(), idx_.end(), 0);
      sort(idx_.begin(), idx_.end(), [&nums] (int a, int b) -> bool
           {
             return nums[a] < nums[b];
           });
      const int N = idx_.size();
      for (int i = 0; i < N; ++i)
        num_idx_[nums[idx_[i]]] = i;
    }
    
    int pick(int target) {
      int idx = num_idx_[target];
      int a = idx;
      int b = idx;
      while (a >= 0 && num_[idx_[a]] == target)
        --a;
      while (b < num_.size() && num_[idx_[b]] == target)
        ++b;
      uniform_int_distribution<int> u(a+1, b-1);
      int p = u(e);

      return idx_[p];
    }

  vector<int> num_;
  vector<int> idx_;
  unordered_map<int, int> num_idx_;
  default_random_engine e;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */


int main (int argc, char *argv[])
{
  vector<int> vec = {0, 1, 1, 3, 4, 1, 3, 2, 4, 1, 3, 2, 1,2,3,3,3};
  Solution su(vec);
  su.pick(1);
  su.pick(2);
  su.pick(3);
  su.pick(3);
  su.pick(3);
  su.pick(1);
  cerr << "Hello World!" << endl;
  return 0;
}
