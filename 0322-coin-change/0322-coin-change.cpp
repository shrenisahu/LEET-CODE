class Solution
{
    public:
        int Solve(int idx, int amount, vector<vector<int>> &dp,vector<int> &coins)
        {
            
            if(amount==0)
                return 0;
            
            if(idx>=coins.size())
                return 1e9;
            
            if(dp[idx][amount]!=-1)
                return dp[idx][amount];

            int notTake=Solve(idx+1,amount,dp,coins);
            int take=1e9;
            if(amount>=coins[idx])
                take=1+Solve(idx,amount-coins[idx],dp,coins);
            
            return dp[idx][amount]= min(take,notTake);
           
        }

   

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount+1,-1));
       	int ans=Solve(0,amount,dp,coins);
        
        if (ans == 1e9)
            return -1;

        return ans;
    }
};