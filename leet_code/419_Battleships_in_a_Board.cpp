class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
      if (board.empty() || board[0].empty())
        return 0;
      const int R = board.size();
      const int C = board[0].size();
      int r = 0;
      int c = 0;
      int count = 0;
      for (int r = 0; r < R; ++r)
      {
        for (int c = 0; c < C; ++c)
        {
          if (board[r][c] == 'X')
          {
            if (!((r-1 >= 0 && board[r-1][c] != '.')
                  || (c-1 >= 0 && board[r][c-1] != '.')))
            {
              ++count;
            }
            
          }
        }
      }
      
      return count;
    }
};
