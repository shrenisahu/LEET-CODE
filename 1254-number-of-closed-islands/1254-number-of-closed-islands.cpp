class Solution {
public:
    int closedIsland(vector<vector<int>>& grid1) {
        vector<vector<int>> grid=grid1;
        int tr=grid.size();
        int tc=grid[0].size();
        int count=0;
        for(int i=0;i<tc;i++)
        {
            if(grid[0][i]==0)
                DFS(0,i,tr,tc,grid);
        }
         for(int i=0;i<tc;i++)
        {
            if(grid[tr-1][i]==0)
                DFS(tr-1,i,tr,tc,grid);
        }
        
        
         for(int i=0;i<tr;i++)
        {
            if(grid[i][0]==0)
                DFS(i,0,tr,tc,grid);
        }
         for(int i=0;i<tr;i++)
        {
            if(grid[i][tc-1]==0)
                DFS(i,tc-1,tr,tc,grid);
        }
        
        
        
        for(int i=0;i<tr;i++)
        {
            for(int j=0;j<tc;j++)
            {
                if(grid[i][j]==0)
                {
                    DFS(i,j,tr,tc,grid);
                    count++;
                }
            }
        }
        
        return count;
    }
    
    
    
    
    void DFS(int cr,int cc,int tr,int tc,vector<vector<int>>& grid)
    {
        
        if(cr <0 || cc <0 || cr>=tr || cc>=tc  || grid[cr][cc]==1)
            return ;
        
        grid[cr][cc]=1;
        
        
        DFS(cr+1,cc,tr,tc,grid);
        DFS(cr-1,cc,tr,tc,grid);
        DFS(cr,cc+1,tr,tc,grid);
        DFS(cr,cc-1,tr,tc,grid);
        
        return ;
    }
};