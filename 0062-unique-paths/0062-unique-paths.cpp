class Solution
{
    public:

        int memoization(int cr, int cc, int tr, int tc, vector<vector < int>> &dp)
        {
            if (cr == tr - 1 && cc == tc - 1)
                return dp[cr][cc] = 1;
            if (cr >= tr || cc >= tc)
                return dp[cr][cc] = 0;
            if (dp[cr][cc] != -1)
                return dp[cr][cc];

            int ans = memoization(cr + 1, cc, tr, tc, dp) + memoization(cr, cc + 1, tr, tc, dp);

            return dp[cr][cc] = ans;
        }

    int tabulation(int m, int n)
    {
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));

        for (int i = 0; i <= m; i++)
        {
            dp[i][n] = 0;
        }

        for (int i = 0; i <= n; i++)
        {
            dp[m][i] = 0;
        }
        dp[m - 1][n - 1] = 1;

        for (int cr = m - 1; cr >= 0; cr--)
        {
            for (int cc = n - 1; cc >= 0; cc--)
            {
                if (dp[cr][cc] == -1)
                {
                    int ans = dp[cr + 1][cc] + dp[cr][cc + 1];
                    dp[cr][cc] = ans;
                }
            }
        }

        return dp[0][0];
    }
    int uniquePaths(int m, int n)
    {
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));
       	// int ans=memoization(0,0,m,n,dp);
        int ans = tabulation(m, n);
        return ans;
    }
};