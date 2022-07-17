class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int totalRow=grid.size();
        int totalCol=grid[0].size();
        int currCount=0;
        int Area=0;
        for(int i=0;i<totalRow;i++)
        {
            for(int j=0;j<totalCol;j++)
            {
                if(grid[i][j]==1)
                {
                    DFS(grid,i,j,totalRow,totalCol,currCount);
                        Area=max(Area,currCount);
                    currCount=0;
                }
                
            }
        }
        
        return Area;
    }
    
    
    void DFS(vector<vector<int>>& grid,int currRow,int currCol,int totalRow,int totalCol,int &currCount)
    {
        if(currRow <0 || currCol <0 || currRow >=totalRow || currCol >=totalCol || grid[currRow][currCol]!=1)
            return ;
        
        grid[currRow][currCol]=0;
        currCount++;
        cout<<currCount<<" ";
        DFS(grid,currRow+1,currCol,totalRow,totalCol,currCount);
        DFS(grid,currRow-1,currCol,totalRow,totalCol,currCount);
        
        DFS(grid,currRow,currCol+1,totalRow,totalCol,currCount);
        DFS(grid,currRow,currCol-1,totalRow,totalCol,currCount);
        
        return ;
        
    }
};