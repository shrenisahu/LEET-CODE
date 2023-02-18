class Solution
{
    vector<int> pos
    { -1, 0, 1 };
    public:
        int memoization(int cr, int cc, int tr, vector<vector < int>> &matrix, vector< vector< int>> &dp)
        {
            if (cc < 0 || cc >= tr)
                return 100000;

            if (cr == tr - 1)
                return dp[cr][cc] = matrix[cr][cc];

            if (dp[cr][cc] != -1)
                return dp[cr][cc];
            int ans = INT_MAX;
            int temp = INT_MAX;
            for (auto i: pos)
            {
                if (cc + i >= 0 && cc + i < tr)
                {
                    int num = matrix[cr][cc] + memoization(cr + 1, cc + i, tr, matrix, dp);
                    ans = min(ans, num);
                }
            }

            return dp[cr][cc] = ans;
        }

    int tabulation(vector<vector < int>> &matrix)
    {
        int n = matrix.size();
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, 0));

        for (int j = n - 1; j >= 0; j--)
        {

            for (int k = n - 1; k >= 0; k--)
            {
                int ld = 100000, rd = 100000, d = 100000;
                if (k - 1 >= 0)
                    ld = dp[j + 1][k - 1];
                d = dp[j + 1][k];
                if (k + 1 < n)
                    rd = dp[j + 1][k + 1];

                dp[j][k] = matrix[j][k] + min({ ld,
                    rd,
                    d });
            }
        }
        int minAns = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            minAns = min(minAns, dp[0][i]);
        }

        return minAns;
    }

    int minFallingPathSum(vector<vector < int>> &matrix)
    {
        int n = matrix.size();
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, -1));

       	// int minAns = INT_MAX;
       	// for (int i = 0; i < n; i++)
       	// {
       	//     int ans = memoization(0, i, n, matrix, dp);
       	//     minAns = min(ans, minAns);
       	// }
        int ans = tabulation(matrix);
        return ans;
       	// return minAns;
    }
};