class Solution
{
    public:
        int sideLen(int i, int j, int tr, int tc, vector<vector < int>> &matrix, vector< vector< int>> &dp)
        {

            if (i >= tr || j >= tc || i < 0 || j < 0 || matrix[i][j] == 0)
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

    int Tabulate(vector<vector < int>> &matrix)
    {
        int count=0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector < int>> dp(n + 2, vector<int> (m + 1, 0));

        for (int cr = 1; cr <= n; cr++)
        {
            for (int cc = 1; cc <= m; cc++)
            {
                if (matrix[cr - 1][cc - 1] == 1)
                {
                    dp[cr][cc] = 1 + min({ dp[cr - 1][cc],
                        dp[cr][cc - 1],
                        dp[cr - 1][cc - 1] });
                    
                    count+=dp[cr][cc];
                }
            }
        }

       

        return count;
    }
    int countSquares(vector<vector < int>> &matrix)
    {
       	
       	
        int ans = Tabulate(matrix);
        return ans;
    }
};