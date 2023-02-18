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
    int minimumTotal(vector<vector < int>> &triangle)
    {

        int m = triangle.size();
        vector<vector < int>> dp(m + 1, vector<int> (m + 1, -1));
        int ans = memoization(0, 0, m, triangle, dp);

        return ans;
    }
};