#include <vector>

using namespace std;

class Solution {
public:
    Solution(void) : done(false) {}

    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }

private:
    bool done;

    bool check(vector<vector<char>>& board, char c, int row, int col)
    {
        for(int i=0; i<9; i++)
        {
            if(c == board[row][i] && i != col)
                return false;
            
            if(c == board[i][col] && i != row)
                return false;

            if(c == board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] && ((row / 3) * 3 + i / 3) != row && ((col / 3) * 3 + i % 3) != col)
                return false;
        }

        return true;
    }

    bool dfs(vector<vector<char>>& board, int row, int col)
    {
        if(board[row][col] == '.')
        {
            for(char c='1'; c<='9'; c++)
            {
                if(check(board, c, row, col) == true)
                {
                    board[row][col] = c;
                    if(col < 8)
                    {
                        if(dfs(board, row, col + 1) == false)
                            board[row][col] = '.';
                    }
                    else if(row < 8)
                    {
                        if(dfs(board, row + 1, 0) == false)
                            board[row][col] = '.';
                    }
                    else
                    {
                        done = true;
                    }
                }
            }
        }
        else
        {
            if(col < 8)
            {
                dfs(board, row, col + 1);
            }
            else if(row < 8)
            {
                dfs(board, row + 1, 0);
            }
            else
            {
                done = true;
            }
        }

        if(done)
        {
            return true;
        }

        return false;
    }
};