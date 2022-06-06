class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int answer=0;
        
        for(int currRow=0; currRow <m;currRow++)
        {
            if(grid[currRow][0]==0) // upper row
            {
                cout<<"1";
                 DFS(currRow,0,m,n,grid);
            }
             
            if(grid[currRow][n-1]==0)  //last row
            {
                cout<<"2";
                DFS(currRow,n-1,m,n,grid);
            }
            
        }
        
        for(int currCol=0;currCol <n;currCol++)
        {
            if(grid[0][currCol]==0)
            
                DFS(0,currCol,m,n,grid); // 1st col
            
            if(grid[m-1][currCol]==0)  // last col
                DFS(m-1,currCol,m,n,grid);
        }
        
         
       
        for(int currRow=0;currRow <m;currRow++)
        {
            for(int currCol=0; currCol < n;currCol++)
            {
                if(grid[currRow][currCol]==0)
                {
                    DFS(currRow,currCol,m,n,grid);
                    answer++;
                }
            }
        }
        
        return answer;
    }
    
    void DFS(int currRow,int currCol,int m,int n,vector<vector<int>>& grid )
    {
        if(currRow <0 || currRow >= m || currCol <0 || currCol >=n || grid[currRow][currCol]==1)
            return ;
        
        grid[currRow][currCol]=1;
        DFS(currRow+1,currCol,m,n,grid);
        DFS(currRow-1,currCol,m,n,grid);
        DFS(currRow,currCol-1,m,n,grid);
        DFS(currRow,currCol+1,m,n,grid);
        return ;
    }
};