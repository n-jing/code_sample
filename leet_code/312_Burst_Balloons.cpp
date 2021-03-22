#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


class Solution {
public:
    int maxCoins(vector<int>& nums) {
      if (nums.empty())
        return 0;

      vector<vector<int>> ele_coin(nums.size(), vector<int>(nums.size(), 0));
      const int N = nums.size();
      for (int i = 1; i <= N; ++i)
      {
        for (int j = 0; j < N-i; ++j)
        {
          for (int z = j; z < j+i; ++z)
          {
            
          }

        }

      }

      
      return CollectCoin(0, expand_nums.size()-1, expand_nums, ele_coin);
    }
};

#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  Solution su;
  vector<int> vec = {0, 1, 0, 8};
  auto coin = su.maxCoins(vec);
  cerr << "coin:" << coin << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
