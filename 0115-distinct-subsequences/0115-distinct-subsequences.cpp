class Solution
{
    public:

        int Solve(int i, int j, string &s, string &t, vector<vector < int>> &dp)
        {

            if (j == 0)
                return 1;
            if (i == 0)
                return 0;
            if (dp[i][j] != -1)
                return dp[i][j];

            if (s[i - 1] == t[j - 1])
            {
                int reduceBoth = Solve(i - 1, j - 1, s, t, dp);
                int reduceS = Solve(i - 1, j, s, t, dp);

                return dp[i][j] = reduceBoth + reduceS;
            }

            return dp[i][j] = Solve(i - 1, j, s, t, dp);
        }

    int Tabulate(string s, string t)
    {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector < double>> dp(n1 + 1, vector<double> (n2 + 1, 0));
        
        for(int i=0;i<=n1;i++)
            dp[i][0]=1;
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    
                }
            }
        }
        return (int)dp[n1][n2];
        
        
    }

    int numDistinct(string s, string t)
    {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector < int>> dp(n1 + 1, vector<int> (n2 + 1, -1));
        // int ans = Solve(n1, n2, s, t, dp);
        int ans= Tabulate(s,t);
        return ans;
    }
};