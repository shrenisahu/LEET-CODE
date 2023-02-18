class Solution
{
    public:
        int memoization(int cr, int cc, int tr, vector<vector < int>> &matrix, vector<vector<int>>&dp)
        {

            if (cr >= tr)
                return  dp[cr][cc]= 0;
            
            if(dp[cr][cc]!=-1)
                return dp[cr][cc];
            
            int leftDiag=10000,down=100000,rightDiag=10000;
            if(cc-1>=0)
            leftDiag = memoization(cr + 1, cc - 1, tr, matrix,dp);

             down = memoization(cr + 1, cc, tr, matrix,dp);
             if(cc+1 <tr)
             rightDiag = memoization(cr + 1, cc + 1, tr, matrix,dp);

            int ans = matrix[cr][cc] + min({ leftDiag,
                down,
                rightDiag });
            return  dp[cr][cc]= ans;
        }

    int minFallingPathSum(vector<vector < int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        int minAns = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int ans = memoization(0, i, n, matrix,dp);
            minAns = min(ans, minAns);
        }

        return minAns;
    }
};