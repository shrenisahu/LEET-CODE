class Solution
{
    public:
        int memoization(int cr, int cc, int tr, int tc, vector<vector < int>> &grid, vector< vector< int>> &dp)
        {

            if (cr >= tr || cc >= tc)
                return 10000;

            if (cr == tr - 1 && cc == tc - 1)
                return dp[cr][cc] = grid[cr][cc];
            if (dp[cr][cc] != -1)
                return dp[cr][cc];

            long long down = grid[cr][cc] + memoization(cr + 1, cc, tr, tc, grid, dp);
            long long left = grid[cr][cc] + memoization(cr, cc + 1, tr, tc, grid, dp);

            return dp[cr][cc] = min(down, left);
        }

    int tabulation(vector<vector < int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n + 1, 1000);
        

        for (int i = m - 1; i >= 0; i--)
        {
            int rightVar = 10000;
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                   
                    dp[j] = grid[i][j];
                    rightVar=grid[i][j];
                }
                else
                {
                    int down = grid[i][j] + dp[j];
                    int right = grid[i][j] + rightVar;

                    dp[j] = min(down, right);
                    rightVar = dp[j];
                }
            }
        }

        return dp[0];
    }

    int minPathSum(vector<vector < int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector < int>> dp(m + 1, vector<int> (n, -1));

       	// int ans = memoization(0, 0, m, n, grid, dp);
        int ans = tabulation(grid);
        return ans;
    }
};