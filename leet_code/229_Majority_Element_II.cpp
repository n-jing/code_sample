class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int c = nums.size() / 3;
      int l = 0;
      int r = 0;

      vector<int> res;
      while (r < nums.size())
      {
        while (r < nums.size() && nums[r] == nums[l])
          ++r;
        if (r-l > c)
        {
          res.push_back(nums[l]);
          l = r;
        } 
      }
      return res;
    }
};
