#include <bits/stdc++.h>
using namespace std;

bool valid(vector<vector<char>> &board, int row, int clm, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == c)
            return false;

        if (board[i][clm] == c)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (clm / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool Sodaku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (valid(board, i, j, c))
                    {
                        board[i][j] = c;

                        if (Sodaku(board) == true)
                            return true;

                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    /* vector<vector<char>> board(9, vector<char>(9));

     // only 1 to 9 chars or space = '.';

     for (int i = 0; i < 9; i++)
     {
         for (int j = 0; j < 9; j++)
         {
             cin >> board[i][j];
         }
     }*/

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Sodaku(board);

    for (auto it : board)
    {
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}