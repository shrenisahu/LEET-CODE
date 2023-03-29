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

    int Solve(int i, int j, string &s, vector<int> &dp)
    {
        if (isPalindrome(i, j, s))
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int ways = 10000;
        for (int k = i; k <= j - 1; k++)
        {

            if (isPalindrome(i, k, s))

            {
                int currAns = 1  + Solve(k + 1, j, s, dp);
                ways = min(ways, currAns);
            }
        }
        return dp[i] = ways;
    }

    int Tabulate(string s)
    {
        int N = s.size();
        vector<int> dp(N + 1, 10000);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (isPalindrome(i, j, s))
                    dp[i] = 0;
            }
        }

        for (int i = N - 1; i >= 0; i--)
        {
           

                
                for (int k = i; k <N-1; k++)
                {
                    if (isPalindrome(i, k,s))
                        
                    {
                         int currAns = 1 + dp[k+1];

                    dp[i]= min(dp[i], currAns);
                    }
                }
            
        }

        return dp[0];
    }

    int minCut(string s)
    {
        int n = s.size();
      
        vector<int> dp(n + 1, -1);
        int ans = Solve(0, n - 1, s, dp);
       	// int ans = Tabulate(s);
        return ans;
    }
};