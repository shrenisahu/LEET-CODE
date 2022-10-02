class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return totalWays(n,k,target,dp);
        
    }
    
    int totalWays(int n,int f,int targetSum, vector<vector<int>>&dp)
    {
        
        
        
        if(n==0 && targetSum==0)
        return 1 ;
        
        if(n==0 || targetSum<=0)
        return 0;    
        
        if(dp[n][targetSum]!=-1)
            return dp[n][targetSum];
        
        int tempAns=0;
        int ways=0;
        int mod=1000000007;
        for(int i=1;i<=f;i++)
        {
            tempAns=totalWays(n-1,f,targetSum-i,dp)%mod;
            // ways=ways%mod;
            // ways=(ways+tempAns)%mod;
            
            
            ways=(ways+tempAns)%mod;
        }
        return  dp[n][targetSum]=ways;
    }
};