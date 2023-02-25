class Solution
{
    public:

        int Solve(int idx, int amount, vector<int> &coins, vector<vector< int>> &dp)
        {

            if (amount == 0)
                return 1;

            if (idx >= coins.size() && amount != 0)
                return 0;
            if (dp[idx][amount] != -1)
                return dp[idx][amount];

            int take = 0;
            if (amount - coins[idx] >= 0)
                take = Solve(idx, amount - coins[idx], coins, dp);

            int notTake = Solve(idx + 1, amount, coins, dp);

            return dp[idx][amount] = take + notTake;
        }

    int Tabulate(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector < int>> dp(n + 1, vector<int> (amount + 1, 0));

        for (int idx = 0; idx <= n; idx++)
            dp[idx][0] = 1;
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int sum = 1; sum <= amount; sum++)

            {
                int take = 0;
                if (sum >= coins[idx])
                    take = dp[idx][sum - coins[idx]];
                int notTake = dp[idx + 1][sum];

                dp[idx][sum] = take + notTake;
            }
        }

        return dp[0][amount];
    }

    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();
        vector<vector < int>> dp(n + 1, vector<int> (amount + 1, -1));
        // int ans = Solve(0, amount, coins, dp);
        int ans=Tabulate(amount,coins);
        return ans;
    }
};