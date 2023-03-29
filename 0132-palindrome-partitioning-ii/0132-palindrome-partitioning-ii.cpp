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

    int Tabulate(string s)
    {
        int N = s.size();
        vector<int> dp(N + 1,0);
        dp[N] = 0;

        for (int i = N - 1; i >= 0; i--)
        {

            int ways = INT_MAX;
            for (int k = i; k < N; k++)
            {

                if (isPalindrome(i, k, s))

                {
                    int currAns = 1 + dp[k + 1];
                    ways = min(ways, currAns);
                }
            }

            dp[i] = ways;
        }

        return dp[0]-1 ;
    }

    int minCut(string s)
    {

        int ans = Tabulate(s);
        return ans;
    }
};