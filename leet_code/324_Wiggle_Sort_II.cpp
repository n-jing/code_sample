#include <iostream>
#include <vector>



using namespace std;



class Solution {
public:
    void wiggleSort(vector<int>& nums) {
      int mid_num = GetMidNum(nums, 0, nums.size()-1);
      int l = 0;
      int r = nums.size()-1;
      int a = 0;
      while (a < r)
      {
        if (nums[a] > mid_num)
        {
          swap(nums[a], nums[r]);
          --r;
        }
        else if (nums[a] < mid_num)
        {
          swap(nums[l], nums[a]);
          ++l;
          ++a;
        }
        else
        {
          ++a;
        }
      }

      int mid_idx = (nums.size()-1) / 2;
      vector<int> sorted_nums(nums.size());
      for (int i = 0; i < nums.size(); ++i)
      {
        if (i%2 == 0)
          sorted_nums[i] = nums[mid_idx-i/2];
        else
          sorted_nums[i] = nums[nums.size()-1-i/2];
      }

      nums = sorted_nums;
    }

  int GetMidNum(vector<int>& nums, int l, int r)
    {
      if (l == r)
        return nums[l];
      int a = l;
      int b = r;
      while (a < b)
      {
        while (a < b && nums[b] > nums[l])
          --b;
        while (a < b && nums[a] <= nums[l])
          ++a;
        swap(nums[a], nums[b]);
      }
      swap(nums[l], nums[a]);
      
      if (a == (nums.size()-1) / 2)
        return nums[a];
      else if (a < (nums.size()-1) / 2)
        return GetMidNum(nums, a+1, r);
      else
        return GetMidNum(nums, l, a-1);
      return nums[0];
    }
};


int main (int argc, char *argv[])
{
  Solution su;
  vector<int> vec = {2, 1};
  su.wiggleSort(vec);
  for (auto v : vec)
  {
    cerr << v << " ";
  }
  cerr << endl;
  return 0;
}
