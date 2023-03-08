class Solution
{
    public:

        int Solve(int i, int j, string word1, string word2,  vector<vector<int>>&dp)
        {

            if (i < 0 && j < 0)
                return 0;

            if (i < 0)
                return j + 1;

            if (j < 0)
                return i + 1;
            if(dp[i][j]!=-1)
                return dp[i][j];

            if (word1[i] == word2[j])
            {
                return dp[i][j]=Solve(i - 1, j - 1, word1, word2,dp);
            }

            int insert = 1 + Solve(i, j - 1, word1, word2,dp);
            int remove = 1 + Solve(i - 1, j, word1, word2,dp);
            int replace = 1 + Solve(i - 1, j - 1, word1, word2,dp);

            return dp[i][j]= min({ insert,
                remove,
                replace });
        }

    int minDistance(string word1, string word2)
    {

        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));

        int ans = Solve(n1 - 1, n2 - 1, word1, word2,dp);
        return ans;
    }
};