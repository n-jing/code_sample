#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      const int n = nums.size();
      int length = n + 1;
      int l_idx = 0;
      int r_idx = 0;
      int sum = 0;
      while (l_idx < n)
      {
        if (r_idx == n && sum - nums[l_idx] < s)
          break;
        if (r_idx < n)
        {
          sum += nums[r_idx];
          ++r_idx;
        }
        while (sum < s && r_idx < n)
        {
          sum += nums[r_idx];
          ++r_idx;
        }
        if (sum >= s)
          length = min(length, r_idx - l_idx);
        while (sum - nums[l_idx] >= s && l_idx < n)
        {
          sum -= nums[l_idx];
          ++l_idx;
        }
        if (sum >= s)
          length = min(length, r_idx - l_idx);
      }
      return (length == n + 1) ? 0 : length;
    }
};


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      const int n = nums.size();
      vector<int> sum(n+1, 0);
      for (int i = 1; i <= n; ++i)
      {
        sum[i] += sum[i-1] + nums[i-1];
      }
      int length = n+1;
      for (int i = 0; i < n; ++i)
      {
        int target = sum[i] + s;
        int r_idx = n;
        int l_idx = i;
        if (target > sum[r_idx])
          continue;
        while (r_idx - l_idx != 1)
        {
          int mid = (r_idx + l_idx) / 2;
          if (target > sum[mid])
            l_idx = mid; 
          else
            r_idx = mid;
        }
        length = min(length, r_idx - i);
      }
      return length == n+1 ? 0 : length;
    }
};


#include <iostream>



int main (int argc, char *argv[])
{
  vector<int> vec = {1, 1};
  Solution su;
  cerr << su.minSubArrayLen(3, vec) << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
