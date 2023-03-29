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
       
        if(i==j)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int ways = 10000;
        for (int k = i; k < j ; k++)
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
        vector<int> dp(N + 1, 0);
        

        for (int i = N - 1; i >= 0; i--)
        {
           int minWays=1000;

                
                for (int k = i; k <=N-1; k++)
                {
                    if (isPalindrome(i, k,s))
                        
                    {
                         int currAns = 1 + dp[k+1];

                    minWays= min(minWays, currAns);
                    }
                }
            dp[i]=minWays;
            
        }

        return dp[0]-1;
    }

    int minCut(string s)
    {
        int n = s.size();
      
        vector<int> dp(n + 1, -1);
        int ans = Solve(0, n, s, dp);
       	// int ans = Tabulate(s);
        return ans-1;
    }
};