class Solution
{
    public:
        int Solve(int idx, int amount, vector<vector < int>> &dp, vector< int > &coins)
        {

            if (amount == 0)
                return 0;

            if (idx >= coins.size())
                return 1e9;

            if (dp[idx][amount] != -1)
                return dp[idx][amount];

            int notTake = Solve(idx + 1, amount, dp, coins);
            int take = 1e9;
            if (amount >= coins[idx])
                take = 1 + Solve(idx, amount - coins[idx], dp, coins);

            return dp[idx][amount] = min(take, notTake);
        }
    int Tabulate(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector < int>> dp(n + 1, vector<int> (amount + 1, 1e9));
        for (int idx = 0; idx <= n; idx++)
            dp[idx][0] = 0;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int sum = 1; sum <= amount; sum++)
            {
                int notTake = dp[idx + 1][sum];
                int take = 1e9;
                if (sum >= coins[idx])
                    take = 1 + dp[idx][sum - coins[idx]];

                dp[idx][sum] = min(take, notTake);
            }
        }

        return dp[0][amount];
    }

    int SpaceOpt(vector<int> &coins, int amount)
    {
        int n = coins.size();

        vector<int> dp(amount + 1, 1e9);

        dp[0] = 0;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            vector<int> temp(amount + 1, 1e9);
            temp[0] = 0;
            for (int sum = 1; sum <= amount; sum++)
            {
                int notTake = dp[sum];
                int take = 1e9;
                if (sum >= coins[idx])
                    take = 1 + temp[sum - coins[idx]];

                temp[sum] = min(take, notTake);
            }
            dp = temp;
        }

        return dp[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector < int>> dp(n + 1, vector<int> (amount + 1, -1));
       	// int ans = Solve(0, amount, dp, coins);
       	// int ans=Tabulate(coins,amount);
        int ans = SpaceOpt(coins, amount);
        if (ans == 1e9)
            return -1;

        return ans;
    }
};