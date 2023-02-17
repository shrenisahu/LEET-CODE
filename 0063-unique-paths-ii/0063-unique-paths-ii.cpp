class Solution
{
    public:
        int mod = 1e9 + 7;

    int memoization(int cr, int cc, int tr, int tc, vector<vector < int>> &dp, vector< vector< int>> &grid)
    {

        if (cr >= tr || cc >= tc || grid[cr][cc] == 1)
            return dp[cr][cc] = 0;

        if (cr == tr - 1 && cc == tc - 1)
            return dp[cr][cc] = 1;
        if (dp[cr][cc] != -1)
            return dp[cr][cc];

        int ans = memoization(cr + 1, cc, tr, tc, dp, grid) + memoization(cr, cc + 1, tr, tc, dp, grid);

        return dp[cr][cc] = ans;
    }

    int Tabulation(vector<vector < int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector < long long >> dp(m + 1, vector<long long> (n + 1, 0));
        if (grid[m - 1][n - 1] == 0)
            dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 0)
                {
                    if (i == m - 1 && j == n - 1)
                        dp[i][j] = 1;
                    else
                    {
                          int ans = ((dp[i + 1][j] ) + (dp[i][j + 1] )) ;
                        dp[i][j]=ans*1LL;
                    
                    }
                }
            }
        }

        return dp[0][0];
    }

    int uniquePathsWithObstacles(vector<vector < int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));
       	// int ans = memoization(0, 0, m, n, dp, grid);
        int ans = Tabulation(grid);

        return ans;
    }
};