class Solution
{
    public:

        bool isPalindrome(int start, int end, string &s)
        {

            while (start <= end)
            {
                if (s[start] != s[end])
                    return false;

                start++;
                end--;
            }
            return true;
        }

    int Solve(int i, int j, string &s, vector<vector < int>> &dp)
    {
        if (isPalindrome(i, j, s))
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ways = 10000;
        for (int k = i; k <= j - 1; k++)
        {

            if (isPalindrome(i, k, s))

            {
                int currAns = 1 + Solve(i, k, s, dp) + Solve(k + 1, j, s, dp);
                ways = min(ways, currAns);
            }
        }
        return dp[i][j] =ways;
    }

    int Tabulate(string s)
    {
        int N = s.size();
        vector<vector < int>> dp(N, vector<int> (N, 10000));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (isPalindrome(i, j, s))
                    dp[i][j] = 0;
            }
        }

        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = i; j <= N - 1; j++)
            {

                int ways = 10000;
                for (int k = i; k <= j - 1; k++)
                {

                    int currAns = 1 + dp[i][k] + dp[k + 1][j];

                    dp[i][j] = min(dp[i][j], currAns);
                }
            }
        }

        return dp[0][N - 1];
    }

    int minCut(string s)
    {
        int n = s.size();
        vector<vector < int>> dp(n, vector<int> (n, -1));
        int ans = Solve(0, n - 1, s, dp);
       	// int ans = Tabulate(s);
        return ans;
    }
};