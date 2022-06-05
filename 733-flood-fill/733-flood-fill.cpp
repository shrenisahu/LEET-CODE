class Solution {
    
    vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
    
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        int m=grid.size();
        int n=grid[0].size();
       vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        int currColor=grid[sr][sc];
        Replace(sr,sc,currColor,newColor,m,n,visited,grid);
        
        return grid;
        
        
    }
    
    void Replace(int currRow,int currCol,int currColor,int newColor ,int m,int n, vector<vector<bool>>&visited,vector<vector<int>>& grid)
    {
        if(currRow < 0 || currCol <0 || currRow >=m || currCol >=n || grid[currRow][currCol]!=currColor || visited[currRow][currCol]==true)
            return ;
            grid[currRow][currCol]=newColor;
            visited[currRow][currCol]=true;
            for(auto eachDir:dir)
            {
                int nextRow=currRow+eachDir[0];
                int nextCol=currCol+eachDir[1];
                Replace(nextRow,nextCol,currColor,newColor,m,n,visited,grid);
                
                
            }
        }
        
    
    
};