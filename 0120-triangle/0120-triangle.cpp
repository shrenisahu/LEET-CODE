class Solution
{
    public:

        int memoization(int cr, int cc, int tr, vector<vector < int>> &triangle, vector< vector< int>> &dp)
        {

            if (cr >= tr)
                return dp[cr][cc] = 0;
            if (dp[cr][cc] != -1)
                return dp[cr][cc];

            int down = triangle[cr][cc] + memoization(cr + 1, cc, tr, triangle, dp);
            int downRight = triangle[cr][cc] + memoization(cr + 1, cc + 1, tr, triangle, dp);

            return dp[cr][cc] = min(down, downRight);
        }

    int tabulation(vector<vector < int>> &triangle)
    {
        int m = triangle.size();
        vector<vector < int>> dp(m + 1, vector<int> (m + 1, 0));
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if(j>i)
                    continue;
                
                int down=triangle[i][j]+dp[i+1][j];
                int downRight=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,downRight);
                
            
            }
        }
        
        return dp[0][0];
    }

    int minimumTotal(vector<vector < int>> &triangle)
    {

        int m = triangle.size();
        vector<vector < int>> dp(m + 1, vector<int> (m + 1, -1));
       	// int ans = memoization(0, 0, m, triangle, dp);
        int ans = tabulation(triangle);

        return ans;
    }
};