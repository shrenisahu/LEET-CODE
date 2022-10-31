class Solution
{
    public:

        queue<vector < int>> line;
    int minDist = 0;
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
    bool isValid(int cr, int cc, int tr, int tc, vector<vector < int>> &grid)
    {
        if (cr < 0 || cc < 0 || cr >= tr || cc >= tc || grid[cr][cc] != 1 || grid[cr][cc] == -2)
            return false;
        return true;
    }
    bool isValid2(int cr, int cc, int tr, int tc, vector<vector < int>> &grid,vector<vector < int>> &visited)
    {
        if (cr < 0 || cc < 0 || cr >= tr || cc >= tc   || visited[cr][cc]==1)
            return false;
        return true;
    }
    int shortestBridge(vector<vector < int>> &grid)
    {

        int tr = grid.size();
        int tc = grid[0].size();
        bool flag = false;
        for (int i = 0; i < tr; i++)
        {
            for (int j = 0; j < tc; j++)
            {
                if (grid[i][j] == 1)
                {
                    BFS(i, j, tr, tc, grid);
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
                 
       
        vector<vector<int>>visited(tr,vector<int>(tc,0));
        while (!line.empty())
        {
           
            vector<int> arr = line.front();
            line.pop();

            int row = arr[0];
            int col = arr[1];
            int dist = arr[2];
            if(visited[row][col]==1)
                continue;
           visited[row][col]=1;
           	if(grid[row][col]==1)
           	{ 	
           	    return dist-1;
           	}

        
            for (int i = 0; i <= 3; i++)
            {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];

                if (isValid2(newRow, newCol, tr, tc, grid,visited))
                {
                 
                  
                    vector<int> num
                    {
                        newRow,
                        newCol,
                        dist + 1
                    };
                    line.push(num);
                }
            }
        }

        return minDist;
    }

    void BFS(int cr, int cc, int tr, int tc, vector<vector < int>> &grid)
    {
        queue<pair<int, int>> que;
        que.push({ cr,
            cc });

        while (!que.empty())
        {
            auto currPair = que.front();
            que.pop();
            int row = currPair.first;
            int col = currPair.second;

            if (grid[row][col] == 2)
                continue;

            vector<int> arr
            {
                row,
                col,
                0
            };
            line.push(arr);
            grid[row][col] = 2;

            for (int i = 0; i <= 3; i++)
            {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];
                if (isValid(newRow, newCol, tr, tc, grid))
                {
                    que.push({ newRow,
                        newCol });
                }
            }
        }
    }
};