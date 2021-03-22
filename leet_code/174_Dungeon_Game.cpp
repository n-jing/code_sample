#include <vector>
#include <iostream>
#include <numeric>
#include <limits>


using namespace std;


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      if (dungeon.empty() || dungeon[0].empty())
        return 0;
      
      const int M = dungeon.size();
      const int N = dungeon[0].size();
      vector<vector<int>> health(M, vector<int>(N, 0));
      if (dungeon.back().back() <= 0)
        health[M-1][N-1] = -dungeon[M-1][N-1] + 1;
      else
        health[M-1][N-1] = 1;

      for (int i = M+N-3; i >= 0; --i)
      {
        for (int j = 0; j <= i; ++j)
        {
          if (i-j >= M || j >= N)
            continue;
          int d = dungeon[i-j][j];
          int rd = numeric_limits<int>::max();
          int cd = numeric_limits<int>::max();
          if (i-j+1 < M)
            rd = health[i-j+1][j];
          if (j+1 < N)
            cd = health[i-j][j+1];
          health[i-j][j] = max(-d + min(rd, cd) + 1, 0);
        }
      }

      return health.front().front() == 0 ? 1: health.front().front();
    }
};


int main (int argc, char *argv[])
{
  vector<vector<int>> vec = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
  Solution su;
  int p = su.calculateMinimumHP(vec);
  cerr << p << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
