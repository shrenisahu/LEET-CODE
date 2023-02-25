class Solution
{
    public:

        int Solve(int idx, int amount, vector<int> &coins, vector<vector<int>>&dp) {
            
            if(amount==0)
                return 1;
            
            if(idx>=coins.size() && amount!=0)
                return 0;
            if(dp[idx][amount]!=-1)
                return dp[idx][amount];
                
                int take=0;
            if(amount-coins[idx] >=0)
            take=Solve(idx,amount-coins[idx],coins,dp);
            
            int notTake=Solve(idx+1,amount,coins,dp);
            
            return  dp[idx][amount]=take+notTake;
            
        }

    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=Solve(0,amount,coins,dp);
        return ans;
    }
};