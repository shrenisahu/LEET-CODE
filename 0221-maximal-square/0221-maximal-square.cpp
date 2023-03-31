class Solution
{
    public:

        int sideLen(int i, int j, int tr, int tc, vector<vector < char>> &matrix, vector< vector< int>> &dp)
        {

            if (i >= tr || j >= tc || i < 0 || j < 0 || matrix[i][j] == '0')
                return 0;
            if (dp[i][j] != -1)
                return dp[i][j];
            int down = 1 + sideLen(i + 1, j, tr, tc, matrix, dp);
            int right = 1 + sideLen(i, j + 1, tr, tc, matrix, dp);
            int diagonal = 1 + sideLen(i + 1, j + 1, tr, tc, matrix, dp);

            return dp[i][j] = min({ down,
                right,
                diagonal });
        }
    int maximalSquare(vector<vector < char>> &matrix)
    {
        int maxArea = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector < int>> dp(n + 2, vector<int> (m + 1, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    int currLen = sideLen(i, j, n, m, matrix, dp);
                    maxArea = max(maxArea, currLen *currLen);
                }
            }
        }

        return maxArea;
    }
};