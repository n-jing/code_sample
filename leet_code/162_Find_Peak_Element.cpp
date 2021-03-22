#include <vector>
#include <iostream>


using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      if (nums.size() < 2)
        return 0;
      int l = 0;
      int r = nums.size()-1;
      return SelectPeakElement(nums, l, r);
    }
  int SelectPeakElement(vector<int> &nums, int l, int r)
    {
      if (r == l+1)
        return nums[r] > nums[l] ? r : l;
      int mid = (r+l)/2;
      if (nums[mid] < nums[mid+1] || nums[mid] > nums[mid-1])
        return SelectPeakElement(nums, mid, r);
      if (nums[mid] > nums[mid+1] || nums[mid] < nums[mid-1])
        return SelectPeakElement(nums, l, mid);
    }
};


int main (int argc, char *argv[])
{

  cerr << "Hello World!" << endl;
  return 0;
}
