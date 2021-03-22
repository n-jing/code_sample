#include <vector>
#include <array>

using namespace std;



class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
      if (board.empty())
        return ;
      const int R = board.size();
      const int C = board.front().size();
      for (int r = 0; r < R; ++r)
      {
        for (int c = 0; c < C; ++c)
        {
          int live_cell = CountLiveCell(board, r, c, R, C);
          int next = 0;
          if (board[r][c])
          {
            if (live_cell == 2 || live_cell == 3)
              next = 1;
            
          }
          else
          {
            if (live_cell == 3)
              next = 1;
          }
          board[r][c] = board[r][c] + 2 * next;
        }
      }

      for (int r = 0; r < R; ++r)
      {
        for (int c = 0; c < C; ++c)
        {
          board[r][c] /= 1;
        }
      }
    }

  int CountLiveCell(vector<vector<int>>& board, int r, int c, int R, int C)
    {
      array<array<int, 2>, 8> neigh = {array<int, 2>{-1, -1}, array<int, 2>{-1, 0}, array<int, 2>{-1, 1},
                                       array<int, 2>{0, -1},           array<int, 2>{0, 1},
                                       array<int, 2>{1, -1}, array<int, 2>{1, 0}, array<int, 2>{1, 1}};
      int count = 0;
      for (int i = 0; i < 8; ++i)
      {
        int nr = r + neigh[i][0];
        int nc = c + neigh[i][1];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C)
          count += board[nr][nc] % 2;
      }

      return count;
    }
};
