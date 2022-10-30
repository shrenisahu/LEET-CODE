class Solution
{
    public:
        vector<vector < int>> colorBorder(vector<vector < int>> &grid, int row, int col, int color) {
            
            int tr=grid.size();
            int tc=grid[0].size();
            if(grid[row][col]==color)
                return grid;
            int oldColor=grid[row][col];
            
           DFS(row,col,tr,tc,grid,grid[row][col],color);
             vector<vector < int>>arr=grid;
            
            for(int i=0;i<tr;i++)
            {
                for(int j=0;j<tc;j++)
                {
                    if(grid[i][j]<0)
                    {
                        if(isBorder(i,j,tr,tc,grid,color))
                            arr[i][j]=color;
                        else
                            arr[i][j]=oldColor;
                            
                            
                        
                        
                        
                    }
                }
            }
            
             
            return arr;
            
        }
    
    
    bool isBorder(int cr,int cc,int tr,int tc,vector<vector < int>> grid,int newColor)
    {
        if(cr==0|| cc==0 || cr ==tr-1 || cc==tc-1 )
            return true;
        
        if(grid[cr+1][cc] >0)
            return true;
        if(grid[cr-1][cc] >0)
            return true;
        if(grid[cr][cc+1] >0)
            return true;
        if(grid[cr][cc-1] >0)
            return true;
       
        
        return false;
        
        
    }

    void DFS(int cr, int cc, int tr, int tc, vector<vector < int>> &grid, int currColor,int newColor)
    {

        if (cr < 0 || cc < 0 || cr >= tr || cc >= tc || grid[cr][cc] != currColor)
            return;
        
        
       
        grid[cr][cc] = -newColor;
        
        
        DFS(cr+1, cc, tr, tc, grid, currColor,newColor);
        DFS(cr-1, cc, tr, tc, grid, currColor,newColor);
        DFS(cr, cc+1, tr, tc, grid, currColor,newColor);
        DFS(cr, cc-1, tr, tc, grid, currColor,newColor);
        
        return ;
    }
    
    
};