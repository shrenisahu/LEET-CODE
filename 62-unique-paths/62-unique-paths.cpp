class Solution
{
    
    public:
        int uniquePaths(int m, int n)
        {
            int currRow = 0;
            int currCol = 0;
            int count = 0;
            vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
            int ans= DFS(0, 0, m, n,dp);
            
           
            return ans;
            
        }

    int DFS(int currRow, int currCol, int totalRow, int totalCol, vector<vector<int>>&dp)
    {

        if (currRow == totalRow - 1 && currCol == totalCol - 1)
        {
            
            
           
          
            return 1;
        }
        if (currRow >= totalRow || currCol >= totalCol || currRow < 0 || currCol < 0)
            return 0;

        if(dp[currRow][currCol]!=-1)
            return dp[currRow][currCol];

        int a = DFS(currRow + 1, currCol, totalRow, totalCol,dp);
        int b = DFS(currRow, currCol + 1, totalRow, totalCol,dp);
        
        return dp[currRow][currCol]=a+b;
    }
};