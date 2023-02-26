class Solution
{
    public:

        int solve(int i1, int i2, string text1, string text2,  vector<vector<int>>&dp)
        {
            if (i1 >= text1.size() || i2 >= text2.size())
                return 0;
            if(dp[i1][i2]!=-1)
                return dp[i1][i2];
            if (text1[i1] == text2[i2])
                return dp[i1][i2]=  1 + solve(i1 + 1, i2 + 1, text1, text2,dp);

           
                int left = solve(i1 + 1, i2, text1, text2,dp);
                int right = solve(i1, i2 + 1, text1, text2,dp);
            

            return dp[i1][i2]=max( left, right);
        }
    
    
    int tabulate(string text1, string text2)
    {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i1=n1-1;i1>=0;i1--)
        {
            for(int i2=n2-1;i2>=0;i2--)
            {
                
                if(text1[i1]==text2[i2])
                    dp[i1][i2]=1+dp[i1+1][i2+1];
                else 
                {
                    int left=dp[i1+1][i2];
                    int right=dp[i1][i2+1];
                    
                    dp[i1][i2]=max(left,right);
                }
            }
            
        }
        return dp[0][0];
        
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        // int ans=solve(0,0,text1,text2,dp);
        int ans=tabulate(text1,text2);
        return ans;
    }
};