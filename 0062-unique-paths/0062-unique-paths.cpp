class Solution {
public:
    
    
    int memoization(int cr,int cc,int tr,int tc, vector<vector<int>>&dp)
    {
        if(cr==tr-1 && cc==tc-1)
            return dp[cr][cc]= 1;
        if(cr>=tr || cc>=tc)
            return dp[cr][cc]=0;
        if(dp[cr][cc]!=-1)
            return dp[cr][cc];
        
        int ans=memoization(cr+1,cc,tr,tc,dp)+memoization(cr,cc+1,tr,tc,dp);
        
        return dp[cr][cc]= ans;
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=memoization(0,0,m,n,dp);
        return ans;
    }
};