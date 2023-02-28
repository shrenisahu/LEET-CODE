class Solution {
public:
    
    string Tabulate(string x, string y)
    {
        int n1=x.size();
        int n2=y.size();
        
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(x[i-1]==y[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    
                }
                else
                {
                    
                    int left=dp[i-1][j];
                    int right=dp[i][j-1];
                    
                    dp[i][j]=max(left,right);
                }
            }
        }
        
      
        string ans="";
        int i=n1;
        int j=n2;
        
        while(i>0 && j>0)
        {
            
            if(x[i-1]==y[j-1])
            {
                ans.push_back(x[i-1]);
                i--;
                j--;
                
            }
            else if(dp[i-1][j] >dp[i][j-1])
            {
                ans.push_back(x[i-1]);
                
                i--;
            }
            else
            {
                 ans.push_back(y[j-1]);
                j--;
            }
            
            
        }
        
        
        while(i>0)
        {
              ans.push_back(x[i-1]);
            i--;
        }
        
        while(j>0)
        {
            ans.push_back(y[j-1]);
            j--;
        }
        
       reverse(ans.begin(),ans.end());
        cout<<ans;
        return ans;
    }
    
    
    
    
    string shortestCommonSupersequence(string str1, string str2) {
        string ans=Tabulate(str2,str1);
       return ans;
    }
};