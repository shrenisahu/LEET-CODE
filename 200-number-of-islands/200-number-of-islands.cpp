class Solution {
    vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int answer=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==false && grid[i][j]=='1')
                {
                    fillIsland(i,j,m,n,grid,visited);
                        answer++;
                }
            }
        }
        
        return answer;
        
        
    }
    
    void fillIsland(int currRow,int currCol,int m,int n,vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        if(isValid(currRow,currCol,m,n,grid,visited))
        {
            visited[currRow][currCol]=true;
             for(auto eachDir:dir)
             {
                 int nextRow=currRow+eachDir[0];
                 int nextCol=currCol+eachDir[1];
                 
                 fillIsland(nextRow,nextCol,m,n,grid,visited);
             }
            
        }
        return ;
    }
    
    
    bool isValid(int currRow,int currCol,int m,int n,vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        return (currRow >= 0 && currRow <m && currCol >=0 && currCol <n && visited[currRow][currCol]==false && grid[currRow][currCol]=='1');
    };
};