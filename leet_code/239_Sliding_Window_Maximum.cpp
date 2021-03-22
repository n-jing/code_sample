#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      if (nums.size() < k || k == 0)
        return {};
      deque<int> dq;
      for (int i = 0; i < k; ++i)
      {
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
          dq.pop_back(); 
        }
        dq.push_back(i);
      }
      vector<int> res;
      for (int i = k-1; i < nums.size(); ++i)
      {
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
          dq.pop_back(); 
        }
        dq.push_back(i);
        while (dq.front() <= i-k)
          dq.pop_front();
        res.push_back(nums[dq.front()]);
      }

      return res;
    }
};

#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  Solution su;
  vector<int> vec = {1,3,-1,-3,5,3,6,7};
  auto res = su.maxSlidingWindow(vec, 3);
  for (auto r : res)
  {
    cerr << r << " ";
  }
  cerr << endl;
  
  return 0;
}
