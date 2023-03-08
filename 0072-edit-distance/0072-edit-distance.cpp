class Solution
{
    public:

        int memo(string word1, string word2)
        {
            int n1 = word1.size();
            int n2 = word2.size();
            vector<vector < int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
          
            for (int j = 0; j <= n2; j++)
            {
                dp[0][j] = j;
            }
            for (int i = 0; i <= n1; i++)
            {
                dp[i][0] = i;
            }

            for (int i = 1; i <= n1; i++)
            {
                for (int j = 1; j <= n2; j++)
                {
                    if (word1[i - 1] == word2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];

                    else
                    {

                        int insert = 1 + dp[i][j - 1];
                        int remove = 1 + dp[i - 1][j];
                        int replace = 1 + dp[i - 1][j - 1];

                        dp[i][j] = min({ insert,
                            remove,
                            replace });
                    }
                }
            }

            return dp[n1][n2];
        }
     int Tabulate(string word1, string word2)
        {
            int n1 = word1.size();
            int n2 = word2.size();
           
            vector<int>dp(n2+1,0);
        
            for (int j = 0; j <= n2; j++)
            {
                dp[j] = j;
            }
          

            for (int i = 1; i <= n1; i++)
            {
                vector<int>temp(n2+1,0);
                temp[0]=i;
                
                for (int j = 1; j <= n2; j++)
                {
                    if (word1[i - 1] == word2[j - 1])
                        temp[j] = dp[j - 1];

                    else
                    {

                        int insert = 1 + temp[j - 1];
                        int remove = 1 + dp[j];
                        int replace = 1 + dp[j - 1];

                        temp[j] = min({ insert,
                            remove,
                            replace });
                    }
                }
                dp=temp;
            }

            return dp[n2];
     }

    int minDistance(string word1, string word2)
    {

        int n1 = word1.size();
        int n2 = word2.size();
        // vector<vector < int>> dp(n1 + 1, vector<int> (n2 + 1, -1));

       	// int ans = Solve(n1, n2, word1, word2, dp);
        // int ans = memo(word1, word2);
        int ans=Tabulate(word1,word2);
        return ans;
    }
};