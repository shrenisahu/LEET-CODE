class Solution
{
    public:
        bool isPalindrome(string &s, int start, int end)

    {
        while (start <= end)
        {
            if (s[start] != s[end])

                return false;
            end--;
            start++;
        }
        return true;
    }
    int Solve(int start, string &s, int count, vector<vector < int>> &dp)
    {

        if (start > s.size()-1)
            return false;
        if (dp[start][count] != -1)
            return dp[start][count];

        if (count == 1)
        {
            if (isPalindrome(s, start, s.size() - 1))
                return dp[start][count] = true;

          else   return dp[start][count] = false;
        }

        bool mainAns = false;
        for (int k = start; k < s.size(); k++)
        {

            if (isPalindrome(s, start, k))
            {
                bool ans = Solve(k + 1, s, count - 1, dp);
                mainAns = mainAns || ans;
            }
        }

        return dp[start][count] = mainAns;
    }

    bool Tabulate(string & s)
    {
        int n = s.size();
        vector<vector < bool>> dp(n + 1, vector<bool> (4, false));

        for (int i = 0; i <= n - 1; i++)
        {
            if (isPalindrome(s, i, s.size() - 1))
                dp[i][1] = true;
        }

        for (int start = n - 1; start >= 0; start--)
        {
            for (int count = 1; count <= 3; count++)
            {

                for (int k = start; k < s.size(); k++)
                {

                    if (isPalindrome(s, start, k))
                    {

                        bool ans = dp[k + 1][count - 1];
                        dp[start][count] = dp[start][count] || ans;
                    }
                }
            }
        }

        return dp[0][3];
    }

    bool checkPartitioning(string s)
    {

        int n = s.size();
        vector<vector < int>> dp(n + 1, vector<int> (4, -1));
        int ans = Solve(0, s, 3, dp);
       	// int ans = Tabulate(s);
        return ans;
    }
};