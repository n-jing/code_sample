class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      int N = nums.size();
      int l = 0;
      int r = 1;
      vector<string> res;
      string str;
      while (l < N)
      {
        while (r < N && nums[r] == nums[r-1]+1)
          ++r;
        if (r == l+1)
        {
          res.push_back(to_string(nums[l]));
          l = r;
          ++r;
        } 
        else
        {
          str = to_string(nums[l]) + "->" + to_string(nums[r-1]);
          res.push_back(str);
          l = r;
          ++r;
        }
      }

      return res;
    }
};
