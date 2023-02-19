class Solution
{
    public:

        int Solve(int r, int c1, int c2, int tc, vector<vector < int>> &grid, vector< vector< vector< int>>> &dp)
        {
            if (c1 < 0 || c1 >= tc || c2 < 0 || c2 >= tc)
                return -10000;

            if (r == grid.size())
                return 0;
            if (dp[r][c1][c2] != -1)
                return dp[r][c1][c2];
            int maxi = -1000;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int temp = -10000;
                    if (c1 + i >= 0 && c2 + j >= 0 && c1 + i < tc && c2 + j < tc)
                    {
                        int val = 0;
                        if (c1 == c2)
                        {
                            val = grid[r][c1];
                        }
                        else
                        {
                            val = grid[r][c1] + grid[r][c2];
                        }
                        temp = val + Solve(r + 1, c1 + i, c2 + j, tc, grid, dp);
                    }
                    maxi = max(temp, maxi);
                }
            }

            return dp[r][c1][c2] = maxi;
        }

    int Tabulation(vector<vector < int>> &grid)
    {
        int tr = grid.size();
        int tc = grid[0].size();
        vector<vector<vector< int>>> dp(tr + 1, vector<vector < int>> (tc + 1, vector<int> (tc + 1, 0)));

        for (int r = tr - 1; r >= 0; r--)
        {
            for (int c1 = 0; c1 < tc; c1++)	// n-1 to 0 aslos works
            {
                for (int c2 = 0; c2 < tc; c2++)
                {
                	// n-1 to 0 aslos works
                    int maxi = -1000;

                    for (int i = -1; i <= 1; i++)
                    {
                        for (int j = -1; j <= 1; j++)
                        {
                            int temp = -10000;
                            if (c1 + i >= 0 && c2 + j >= 0 && c1 + i < tc && c2 + j < tc)
                            {
                                int val = 0;
                                if (c1 == c2)
                                {
                                    val = grid[r][c1];
                                }
                                else
                                {
                                    val = grid[r][c1] + grid[r][c2];
                                }
                                temp = val + dp[r + 1][c1 + i][c2 + j];
                            }
                            maxi = max(temp, maxi);
                        }
                    }

                    dp[r][c1][c2] = maxi;
                }
            }
        }

        return dp[0][0][tc - 1];
    }

    int spaceOptimization(vector<vector < int>> &grid)
    {
        int tr = grid.size();
        int tc = grid[0].size();
       
        vector<vector < int>> dp(tc + 1, vector<int> (tc + 1, 0));
         vector<vector < int>> temp(tc + 1, vector<int> (tc + 1, 0));
        for (int r = tr - 1; r >= 0; r--)
        {
            for (int c1 = 0; c1 < tc; c1++)	
            {
                for (int c2 = 0; c2 < tc; c2++)
                {
                	
                    int maxi = -1000;

                    for (int i = -1; i <= 1; i++)
                    {
                        for (int j = -1; j <= 1; j++)
                        {
                            int temp = -10000;
                            if (c1 + i >= 0 && c2 + j >= 0 && c1 + i < tc && c2 + j < tc)
                            {
                                int val = 0;
                                if (c1 == c2)
                                {
                                    val = grid[r][c1];
                                }
                                else
                                {
                                    val = grid[r][c1] + grid[r][c2];
                                }
                                temp = val + dp[c1 + i][c2 + j];
                            }
                            maxi = max(temp, maxi);
                        }
                    }

                    temp[c1][c2] = maxi;
                }
            }
            dp=temp;
        }

        return dp[0][tc - 1];
    }

    int cherryPickup(vector<vector < int>> &grid)
    {

        int tr = grid.size();
        int tc = grid[0].size();
        vector<vector<vector< int>>> dp(tr + 1, vector<vector < int>> (tc + 1, vector<int> (tc + 1, -1)));

       	// int ans = Solve(0, 0, tc - 1, tc, grid, dp);
        int ans = spaceOptimization(grid);
        return ans;
    }
};