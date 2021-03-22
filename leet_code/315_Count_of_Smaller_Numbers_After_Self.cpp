#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>


using namespace std;



class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
      vector<int> count(nums.size());
      const int N = nums.size();
      vector<int> sorted_nums;
      for (int i = N-1; i >= 0; --i)
      {
        auto ptr = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]);
        count[i] = distance(sorted_nums.begin(), ptr);

        sorted_nums.insert(ptr, nums[i]);
      }

      return count;
    }
};


#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  vector<int> vec = {};
  Solution su;
  auto v = su.countSmaller(vec);
  cerr << "MMMMMMMMMMMMMMMM" << endl;
  for (auto i : v)
  {
    cerr << i << " ";
  }
  cerr << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
