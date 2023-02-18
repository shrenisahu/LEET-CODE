class Solution
{
    vector<int> pos
    { -1, 0, 1 };
    public:
        int memoization(int cr, int cc, int tr, vector<vector < int>> &matrix, vector< vector< int>> &dp)
        {
            if (cc < 0 || cc >= tr)
                return 100000;

            if (cr >= tr)
                return dp[cr][cc] = 0;

            if (dp[cr][cc] != -1)
                return dp[cr][cc];
            int ans = INT_MAX;
            int temp = INT_MAX;
            for (auto i: pos)
            {
                if (cc + i >= 0 && cc + i < tr)
                {
                    int num = matrix[cr][cc]+memoization(cr + 1, cc + i, tr, matrix, dp);
                    ans = min(ans, num);
                }
            }

           
            return dp[cr][cc] = ans;
        }

    int minFallingPathSum(vector<vector < int>> &matrix)
    {
        int n = matrix.size();
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, -1));

        int minAns = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int ans = memoization(0, i, n, matrix, dp);
            minAns = min(ans, minAns);
        }

        return minAns;
    }
};