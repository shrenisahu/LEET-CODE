class Solution
{
    public:

        int LCS(int i, int j, string s1, string s2, vector<vector < int>> &dp)
        {
            if (i >= s1.size() || j >= s2.size())
                return 0;
            if (dp[i][j] != -1)
                return dp[i][j];
            if (s1[i] == s2[j])
            {
                return dp[i][j] = 1 + LCS(i + 1, j + 1, s1, s2, dp);
            }

            int left = LCS(i + 1, j, s1, s2, dp);
            int right = LCS(i, j + 1, s1, s2, dp);

            return dp[i][j] = max(left, right);
        }

    int Tabulate(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector < int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
        
        
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(word1[i]==word2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else
                {
                    int right=dp[i+1][j];
                    int left=dp[i][j+1];
                    
                    dp[i][j]=max(left,right);
                    
                }
            }
        }
        
        
        return dp[0][0];
    }
    
    
      int spaceOpt(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();
        // vector<vector < int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
        
        vector<int>dp(n2+1,0);
        for(int i=n1-1;i>=0;i--)
        {
             vector<int>temp(n2+1,0);
            for(int j=n2-1;j>=0;j--)
            {
                if(word1[i]==word2[j])
                {
                    temp[j]=1+dp[j+1];
                }
                else
                {
                    int right=dp[j];
                    int left=temp[j+1];
                    
                   temp[j]=max(left,right);
                    
                }
            }
            dp=temp;
        }
        
        
        return dp[0];
      }
    
    

    int minDistance(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector < int>> dp(n1 + 1, vector<int> (n2 + 1, -1));

        // int ans = LCS(0, 0, word1, word2, dp);
        // int ans=Tabulate(word1,word2);
           int ans=spaceOpt(word1,word2);
        int FinalAns = n1 + n2 - (2 *ans);
        return FinalAns;
    }
};