class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int answer=0;
        for(int currRow=0;currRow<m;currRow++)
        {
            for(int currCol=0;currCol <n;currCol++)
            {
                if(grid[currRow][currCol]=='1')
                {
                      sinkIsland(currRow,currCol,m,n,grid);
                          answer+=1;
                }
            }
        }
        return answer;
        
        
    }
    
    
    void sinkIsland(int currRow,int currCol,int m,int n,vector<vector<char>>& grid)
    {
        if(currRow<0 || currRow >=m || currCol <0 || currCol >=n || grid[currRow][currCol]!='1'){
            return ;
        }
        
        
        grid[currRow][currCol]='0'; 
        
        sinkIsland(currRow+1,currCol,m,n,grid);
        sinkIsland(currRow-1,currCol,m,n,grid);
        sinkIsland(currRow,currCol-1,m,n,grid);
        sinkIsland(currRow,currCol+1,m,n,grid);
        
        // return;
        
        
        
    }
};