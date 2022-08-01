class Solution
{
    
    public:
        int uniquePaths(int m, int n)
        {
            int totalSteps=(m-1)+(n-1);
            
            long  ans=1;
            
            int c=min(n,m)-1; // 
            for(int i=1;i<=c;i++)
            {
                ans=ans*(totalSteps-i+1) / i;
            }
         
            
           
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