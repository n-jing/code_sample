#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
      if (matrix.empty() || matrix[0].empty())
        return vector<vector<int>>(0);
      
      const int R = matrix.size();
      const int C = matrix[0].size();

      vector<vector<bool>> east_pac(R, vector<bool>(C, false));
      vector<vector<bool>> west_pac(R, vector<bool>(C, false));

      for (int i = 0; i < R; ++i)
      {
        for (int j = 0; j < C; ++j)
        {
          if (i * j == 0)
            east_pac[i][j] = true;
          else if (east_pac[i][j])
            continue;
          else if ((east_pac[i-1][j] && matrix[i][j] >= matrix[i-1][j])
                || (east_pac[i][j-1] && matrix[i][j] >= matrix[i][j-1]))
            east_pac[i][j] = true;
          else
          {
            if (EastSearch(i, j, east_pac, matrix))
              east_pac[i][j] = true;
          }
        }
      }
      
      for (int i = R-1; i >= 0; --i)
      {
        for (int j = C-1; j >= 0; --j)
        {
          if (i == R-1 || j == C-1)
          {
            west_pac[i][j] = true;
            continue; 
          }
          else if ((west_pac[i][j+1] && matrix[i][j] >= matrix[i][j+1])
                   || (west_pac[i+1][j] && matrix[i][j] >= matrix[i+1][j]))
            west_pac[i][j] = true;
          else
          {
            if (WestSearch(i, j, west_pac, matrix))
              west_pac[i][j] = true;
          }
        }
      }

      vector<vector<int>> land;
      for (int i = 0; i < R; ++i)
      {
        for (int j = 0; j < C; ++j)
        {
          if (east_pac[i][j] && west_pac[i][j])
            land.push_back(vector<int>{i, j});
        }
      }
      
      return land;
    }
  bool WestSearch(int r, int c, vector<vector<bool>> &west_pac, const vector<vector<int>>& matrix)
    {
      if (r == matrix.size()-1 || c == matrix[0].size()-1)
      {
        return true;
      }
      else if ((west_pac[r][c+1] && matrix[r][c] >= matrix[r][c+1])
               || (west_pac[r+1][c] && matrix[r][c] >= matrix[r+1][c]))
        return true;
      else
      {
        if (r-1 >= 0 && matrix[r][c] >= matrix[r-1][c] && WestSearch(r-1, c, west_pac, matrix))
        {
          west_pac[r-1][c] = true;
          return true;
        }
        if (c-1 >= 0 && matrix[r][c] >= matrix[r][c-1] && WestSearch(r, c-1, west_pac, matrix))
        {
          west_pac[r][c-1] = true;
          return true;
        }
      }

      return false;
    }

  bool EastSearch(int r, int c, vector<vector<bool>> &east_pac, const vector<vector<int>>& matrix)
    {
      if (r * c == 0)
      {
        return true;
      }
      else if ((east_pac[r-1][c] && matrix[r][c] >= matrix[r-1][c])
               || (east_pac[r][c-1] && matrix[r][c] >= matrix[r][c-1]))
      {
        return true;
      } 
      else
      {
        if (c+1 < matrix[0].size() && matrix[r][c] >= matrix[r][c+1])
        {
          if (EastSearch(r, c+1, east_pac, matrix))
          {
            east_pac[r][c+1] = true;
            return true;
          }
        }
        if (r+1 < matrix.size() && matrix[r][c] >= matrix[r+1][c])
        {
          if (EastSearch(r+1, c, east_pac, matrix))
          {
            east_pac[r+1][c] = true;
            return true;
          }
        }
      }

      return false;
    }
};

int main (int argc, char *argv[])
{
  vector<vector<int>> mt = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
  Solution su;
  auto res = su.pacificAtlantic(mt);
  for (auto v : res)
  {
    cout << v[0] << " " << v[1] << endl;
  }

  cerr << "Hello World!" << endl;
  return 0;
}
