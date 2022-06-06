class Solution
{

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
    public:
        int numIslands(vector<vector < char>> &grid)
        {
            int m = grid.size();
            int n = grid[0].size();
            int answer = 0;
            for (int currRow = 0; currRow < m; currRow++)
            {
                for (int currCol = 0; currCol < n; currCol++)
                {
                    if (grid[currRow][currCol] == '1')
                    {
                        sinkIsland(currRow, currCol, m, n, grid);
                        answer += 1;
                    }
                }
            }
            return answer;
        }

    void sinkIsland(int currRow, int currCol, int m, int n, vector<vector < char>> &grid)
    {
        grid[currRow][currCol] = '0';
        queue<pair<int, int>> que;
        que.push({ currRow,currCol });
        
        while (!que.empty())
        {
            int Row = que.front().first;
            int Col = que.front().second;
                    
            que.pop();
            for(int i=0;i<dir.size();i++)
            {
                int nextRow=Row+dir[i][0];
                int nextCol=Col+dir[i][1];
               
                
              
                if(isValid(nextRow,nextCol,m,n,grid))
                {
                    

                        grid[nextRow][nextCol]='0';
                        que.push({nextRow,nextCol});
                    
                    
                }
                    
                
             }
        }
    }


bool isValid(int currRow, int currCol, int m, int n, vector<vector < char>> &grid)
{
   if(currRow <0 || currCol <0 || currRow >=m || currCol >=n || grid[currRow][currCol]!='1')
       return false;
    return true;
}
};