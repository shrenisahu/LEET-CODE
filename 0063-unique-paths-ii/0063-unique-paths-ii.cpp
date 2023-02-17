class Solution {
public:
    
    
    int memoization(int cr, int cc, int tr, int tc, vector<vector < int>> &dp,vector<vector<int>>& grid)
        {
           
           
            if (cr >= tr || cc >= tc || grid[cr][cc]==1)
                return dp[cr][cc] = 0;
        
         if (cr == tr - 1 && cc == tc - 1)
                return dp[cr][cc] = 1;
            if (dp[cr][cc] != -1)
                return dp[cr][cc];

            int ans = memoization(cr + 1, cc, tr, tc, dp,grid) + memoization(cr, cc + 1, tr, tc, dp,grid);

            return dp[cr][cc] = ans;
        }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
         vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));
       	int ans=memoization(0,0,m,n,dp,grid);
        
        return ans;
        
    }
};