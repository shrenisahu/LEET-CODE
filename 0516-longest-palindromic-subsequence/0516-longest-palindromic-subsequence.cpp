class Solution
{
    public:

        int Solve(int i, int j, string s1, string s2, vector<vector < int>> &dp)
        {

            if (i >= s1.size() || j >= s2.size())
                return 0;

            if (dp[i][j] != -1)
                return dp[i][j];

            if (s1[i] == s2[j])
                return dp[i][j] = 1 + Solve(i + 1, j + 1, s1, s2, dp);

            int left = Solve(i + 1, j, s1, s2, dp);
            int right = Solve(i, j + 1, s1, s2, dp);
            return dp[i][j] = max(right, left);
        }

    int Tabulate(string &s)
    {
        int n = s.size();
        // vector<vector < int>> dp(n + 1, vector<int> (n + 1, 0));
        string t = s;
        reverse(t.begin(), t.end());
        vector<int>dp(n+1,0);
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int>temp(n+1,0);
            for (int j = n - 1; j >= 0; j--)
            {
                if (s[i] == t[j])
                {
                    temp[j] = 1 + dp[j + 1];
                }
                else
                {
                    int left = dp[j];
                    int right = temp[j + 1];

                    temp[j] = max(left, right);
                }
            }
            dp=temp;
        }

        return dp[0];
    }

    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, -1));
        string t = s;
        reverse(t.begin(), t.end());
       	// int ans = Solve(0, 0, s, t, dp);

        int ans = Tabulate(s);
        return ans;
    }
};