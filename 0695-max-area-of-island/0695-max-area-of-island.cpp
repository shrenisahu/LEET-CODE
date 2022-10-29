class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
        int tr=grid.size();
        int tc=grid[0].size();
        int maxAns=0;
        for(int i=0;i<tr;i++)
        {
            for(int j=0;j<tc;j++)
            {
                if(grid[i][j]==1)
                {
                    int count=0;
                    DFS(i,j,tr,tc,grid,count);
                    maxAns=max(maxAns,count);
                        
                }
            }
        }
        return maxAns;
        
        
    }
    
    
    void DFS(int cr,int cc,int tr,int tc,vector<vector<int>>& grid,int &count)
    {
        
        if(cr<0 || cc <0 || cr>=tr || cc>=tc || grid[cr][cc]==0)
            return ;
        
        count++;
        grid[cr][cc]=0;
          DFS(cr+1,cc,tr,tc,grid,count);
          DFS(cr-1,cc,tr,tc,grid,count);
          DFS(cr,cc+1,tr,tc,grid,count);
          DFS(cr,cc-1,tr,tc,grid,count);
        
        return ;
        
    }
};