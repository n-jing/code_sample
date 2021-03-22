#include <vector>
#include <unordered_set>
#include <array>
#include <set>
#include <iostream>

using namespace std;



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      if (matrix.empty() || matrix[0].empty())
        return 0;
      vector<vector<bool>> m_ones(matrix.size(), vector<bool>(matrix[0].size(), false));
      const int R = matrix.size();
      const int C = matrix[0].size();
      bool all_zero = true;
      for (int r = 0; r < R; ++r)
      {
        for (int c = 0; c < C; ++c)
        {
          if (matrix[r][c] == '1')
          {
            all_zero = false;
            m_ones[r][c] = true;
          } 
        }
      }
      if (all_zero)
        return 0;

      vector<vector<bool>> square = m_ones;
      int length = 1;
      while (true)
      {
        vector<vector<bool>> square_next = square;
        bool next_square_find = false;
        for (int r = 0; r < R; ++r)
        {
          for (int c = 0; c < C; ++c)
          {
            if (square[r][c])
            {
              bool is_next_square = true;
              for (int rd = 0; rd <= length; ++rd)
              {
                if (r+rd >= R || c+length >= C || m_ones[r+rd][c+length] == false)
                {
                  is_next_square = false;
                  break;
                }
              }

              for (int cd = 0; cd <= length; ++cd)
              {
                if (r+length >= R || c+cd >= C || m_ones[r+length][c+cd] == false)
                {
                  is_next_square = false;
                  break;
                }
              }
              if (is_next_square == false)
                square_next[r][c] = false;
              else
                next_square_find = true;
            }
          }
        }

        if (next_square_find)
        {
          square = square_next;
          ++length;
        } 
        else
          break;
      }

      return length*length;
    }
};


#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  vector<vector<char>> m = {{'1','0','1','1','0'},
                            {'1','0','1','1','1'},
                            {'1','1','1','1','1'},
                            {'1','0','0','1','0'}};
  Solution su;
  cerr << su.maximalSquare(m) << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
