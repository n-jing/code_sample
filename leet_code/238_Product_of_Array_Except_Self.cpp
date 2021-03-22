class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int zero_num = 0;
    for (auto n : nums)
    {
      if (n == 0)
        ++zero_num;
    }

    if (zero_num >= 2)
      return vector<itn>(nums.size(), 0);
    else if (zero_num == 1)
    {
      int mul = 1;
      for (auto n : nums)
      {
        if (n != 0)
          mul *= n;
      } 
      vector<int> res = nums;
      for (auto &r : res)
      {
        if (r == 0)
          r == mul;
        else
          r == 0;
      }
      return res;
    }
    else
    {
      int mul = 1;
      for (auto n : nums)
        mul *= n;
      vector<int> res = nums;
      for (auto &r : res)
      {
        r = mul / r;
      }

      return res;
    }
  }
};
