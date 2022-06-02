#include <bits/stdc++.h>
using namespace std;
void printBoard(vector<int> nums, int m, int n)
{
    for (auto temp : nums)
    {
        cout << temp << "  ";
    }
    cout << endl;
}
void PrintPaths(int currRow, int currCol, vector<int> currAns, int m, int n, vector<vector<int>> &board)
{
    if (currRow < 0 || currRow >= m || currCol < 0 || currCol >= n)
        return;

    if (currRow == m - 1 && currCol == n - 1)
    {
        currAns.push_back(board[currRow][currCol]);
        printBoard(currAns, m, n);
        currAns.pop_back();
        return;
    }

    currAns.push_back(board[currRow][currCol]);
    PrintPaths(currRow + 1, currCol, currAns, m, n, board);
    currAns.pop_back();
    currAns.push_back(board[currRow][currCol]);
    PrintPaths(currRow, currCol + 1, currAns, m, n, board);
    currAns.pop_back();
    return;
}

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int>> board(m, vector<int>(n));
    int move = 1;
    vector<int> currAns;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = move;
            move++;
        }
    }

    PrintPaths(0, 0, currAns, m, n, board);

    return 0;
}
