#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      if (nums.empty())
        return 0;
      sort(nums.begin(), nums.end());

      if (target < *min_element(nums.begin(), nums.end()))
        return 0;
      vector<int> com(target, -1);
      return CountCombination(nums, target, com);
    }
  int CountCombination(vector<int>& nums, int target, vector<int> &com)
    {
      if (target == 0)
        return 1;
      if (target < 0)
        return 0;

      if (com[target-1] != -1)
        return com[target-1];
      
      const int N = nums.size();
      int count = 0;
      for (int i = 0; i < N; ++i)
      {
        if (nums[i] > target)
          break;
        count += CountCombination(nums, target-nums[i], com);
      }

      com[target-1] = count;
      return count;
    }
};


int main (int argc, char *argv[])
{
  vector<int> vec = {1, 2};
  Solution su;
  int p = su.combinationSum4(vec, 4);
  cout << p << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
