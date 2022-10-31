class Solution
{
    public:
        vector<vector < int>> dir
        {
            { 1,
                0 },
            { -1,
                0 },
            { 0,
                1 },
            { 0,
                -1 }
        };
    int orangesRotting(vector<vector < int>> &grid)
    {
        int tr = grid.size();
        int tc = grid[0].size();
        int minTime = 0;

        queue<vector < int>> que;
        for (int i = 0; i < tr; i++)
        {
            for (int j = 0; j < tc; j++)
            {
                if (grid[i][j] == 2)
                {
                    vector<int> temp
                    {
                        i,
                        j,
                        0
                    };
                    que.push(temp);
                }
            }
        }

        while (!que.empty())
        {
            vector<int> arr = que.front();
            que.pop();
            int row = arr[0];
            int col = arr[1];
            int dist = arr[2];
           if(grid[row][col]==-2)
               continue;
            grid[row][col] = -2;
            minTime = max(minTime, dist);

            for (int i = 0; i <= 3; i++)
            {

                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];
                if (isValid(newRow, newCol, tr, tc, grid))
                {
                    vector<int> tempArray
                    {
                        newRow,
                        newCol,
                        dist + 1
                    };
                    que.push(tempArray);
                }
            }
        }

        for (int i = 0; i < tr; i++)
        {
            for (int j = 0; j < tc; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return minTime;
    }

    bool isValid(int cr, int cc, int tr, int tc, vector<vector < int>> &grid)
    {
        if (cr < 0 || cc < 0 || cr >= tr || cc >= tc || grid[cr][cc] != 1)
            return false;

        return true;
    }
};