class Solution
{
    public:
        int Solve(vector<int> &coins, int amount,vector<int>&dp)
        {

            if (amount == 0)
                return 0;
            if(dp[amount]!=-1)
                return dp[amount];

            int minAns = 1000000;
            for (int i = 0 ;i < coins.size(); i++)
            {
                int elem = coins[i];
                int temp=1000000;
                if(amount>=coins[i])
                 temp = 1 + Solve(coins, amount - coins[i],dp);
                minAns = min(minAns, temp);
            }

            return dp[amount]=minAns;
        }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int>dp(amount+1,-1);
        int ans=Solve(coins,amount,dp);
        
        if(ans==1000000)
            return -1;
        
        return ans;
    }
};