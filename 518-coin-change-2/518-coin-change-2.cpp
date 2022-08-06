class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
     return noOfWays(amount,coins,0,dp);   
    }
    
    
    int noOfWays(int target,vector<int>& coins,int start,vector<vector<int>>&dp)
    {
    if(target <0)
        return 0;
        
        if(target==0)
            return 1;
        int ans=0;
        if(dp[target][start]!=-1)
            return dp[target][start];
        for(int i=start ;i<coins.size();i++)
        {
            
            ans+=noOfWays(target-coins[i],coins,i,dp);
        }
        return dp[target][start]=ans;
    }
    
};