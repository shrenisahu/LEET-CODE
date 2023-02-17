class Solution
{
    public:
        int memoization(int cr, int cc, int tr, int tc, vector<vector < int>> &grid,    vector<vector<int>>&dp)
        {

            if (cr >= tr || cc >= tc)
                return 10000;

            if (cr == tr - 1 && cc == tc - 1)
                return dp[cr][cc]= grid[cr][cc];
            if(dp[cr][cc]!=-1)
                  return dp[cr][cc];

            long long down = grid[cr][cc] + memoization(cr + 1, cc, tr, tc, grid,dp);
            long long left = grid[cr][cc] + memoization(cr, cc + 1, tr, tc, grid,dp);
            
            return dp[cr][cc]=min(down,left);
        }

    int minPathSum(vector<vector < int>> &grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n,-1));
      
        int ans=memoization(0,0,m,n,grid,dp);
        
        return ans;
    }
};