#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>> &chess, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chess[i][j] << "  ";
        }
        cout << endl;
    }
}

void findSolution(vector<vector<int>> &chess, int currRow, int currCol, int n, int upcomingMove)
{

    if (currRow < 0 || currRow >= n || currCol < 0 || currCol >= n || chess[currRow][currCol] != -1)
    {
        return;
    }

    if (upcomingMove == n * n - 1)
    {

        chess[currRow][currCol] = upcomingMove;
        printBoard(chess, n);
        cout << endl;
        chess[currRow][currCol] = -1;
    }

    
    chess[currRow][currCol] = upcomingMove;
    findSolution(chess, currRow - 2, currCol - 1, n, upcomingMove + 1);
    findSolution(chess, currRow - 2, currCol + 1, n, upcomingMove + 1);

    findSolution(chess, currRow + 2, currCol - 1, n, upcomingMove + 1);
    findSolution(chess, currRow + 2, currCol + 1, n, upcomingMove + 1);

    findSolution(chess, currRow - 1, currCol - 2, n, upcomingMove + 1);
    findSolution(chess, currRow - 1, currCol + 2, n, upcomingMove + 1);

    findSolution(chess, currRow + 1, currCol - 2, n, upcomingMove + 1);
    findSolution(chess, currRow + 1, currCol + 2, n, upcomingMove + 1);

    chess[currRow][currCol] = -1;
    return;
}
int main()

{
    int n = 5;
    vector<vector<int>> chess(n, vector<int>(n, -1));
   
         for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {

               findSolution(chess,i,j,n,0);
           }
       }
}
