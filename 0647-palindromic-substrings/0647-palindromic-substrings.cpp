class Solution
{
    public:

        int countSubstrings(string s)
        {

            int n = s.size();
            vector<vector < int>> dp(n + 1, vector<int> (n + 1, 0));

            int count = 0;
            for (int i = 0; i < n; i++)
            {
                dp[i][i] = 1;
            }

            for (int i = n - 1; i >= 0; i--)
            {

                for (int j = n - 1; j >= 0; j--)
                {
                    
                    if(i>j)
                        continue;
                    if (j - i + 1 == 1)
                    {
                        dp[i][j] = 1;
                    }
                    else if (j - i + 1 == 2)
                    {
                        if (s[i] == s[j])
                            dp[i][j] = 1;
                    }
                    
                    else if (j - i + 1 > 2)

                    {
                        if (s[i] == s[j] && dp[i + 1][j - 1] == 1)

                        {

                            dp[i][j] = 1;
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    

                    if (dp[i][j] == 1)
                        count++;
                }
               
            }

            return count;
        }
};