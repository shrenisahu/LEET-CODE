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
        int minTime=0;
        vector<vector < int>> count(tr, vector<int> (tc, -1));
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

            if (count[row][col] != -1)
                continue;
            minTime=max(minTime,dist);
            count[row][col] = dist;

            for (int i = 0; i <= 3; i++)
            {

                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];
                if (isValid(newRow,newCol,tr,tc,grid,count))
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
        
        for(int i=0;i<tr;i++)
        {
            for(int j=0;j<tc;j++)
            {
                if(grid[i][j]==1 && count[i][j]==-1)
                    return -1;
            }
        }
        
        return minTime;
    }

    bool isValid(int cr, int cc, int tr, int tc, vector<vector < int>> &grid, vector< vector< int>> &count)
    {
        if (cr < 0 || cc < 0 || cr >= tr || cc >= tc || count[cr][cc] != -1 || grid[cr][cc] == 2 || grid[cr][cc] == 0)
            return false;

        return true;
    }
};