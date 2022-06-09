class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        if(grid[sr][sc]==newColor)
            return grid;
        int m=grid.size();
        int n=grid[0].size();
        
        int currColor=grid[sr][sc];
        
        DFS(sr,sc,m,n,currColor,newColor,grid);
        return grid;
        
        
    }
    
    void DFS(int  currRow,int currCol,int m,int n ,int currColor,int newColor,vector<vector<int>>& grid)
    {
        
        
        
        
        if(currRow <0 || currRow >=m || currCol <0 || currCol >=n || grid[currRow][currCol]!=currColor) 
        {
            return ;
        }
        
        grid[currRow][currCol]=newColor;
        
        
        DFS(currRow-1,currCol,m,n,currColor,newColor,grid);
        DFS(currRow+1,currCol,m,n,currColor,newColor,grid);
        DFS(currRow,currCol-1,m,n,currColor,newColor,grid);
        DFS(currRow,currCol+1,m,n,currColor,newColor,grid);
        
        // return ;
        
        
    }
};