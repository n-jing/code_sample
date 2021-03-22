#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <set>
#include <array>

using namespace std;


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
      multiset<array<int, 2>> all_build;
      for (const auto &b : buildings)
      {
        all_build.emplace(array<int, 2>{b[0], -b[2]});
        all_build.emplace(array<int, 2>{b[1], b[2]});
      }

      multiset<int> height = {0};
      vector<vector<int>> skyline;
      int cur_height = 0;
      for (const auto &b : all_build)
      {
        if (b[1] < 0)
          height.insert(-b[1]);
        if (b[1] > 0)
          height.erase(height.find(b[1]));
        int h = *(height.rbegin());
        if (h != cur_height)
        {
          skyline.push_back(move(vector<int>{b[0], h}));
          cur_height = h;
        }
      }

      return skyline;
    }
};



#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  vector<vector<int>> b = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
  // vector<vector<int>> b = {{0,2147483647,2147483647}};
  Solution su;
  auto h = su.getSkyline(b);
  for (auto i : h)
  {
    for (auto j : i)
    {
      cerr << j << " ";
    }
    cerr << endl;
  }

  cerr << "Hello World!" << endl;
  return 0;
}
