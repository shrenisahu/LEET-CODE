class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int n = prices.size() + 1;
            vector<vector<vector< int>>> dp(n, vector<vector < int>> (2, vector<int> (2, -1)));
            int ans = Profit(0, 1, 1, prices, dp);
            if (ans < 0)
                return 0;

            return ans;
        }

    int Profit(int currIndex, int canBuy, int transactionCount, vector<int> &prices, vector<vector< vector< int>>> &dp)

    {

        if (currIndex >= prices.size() && transactionCount > 0)
            return -10000;

        if (transactionCount == 0 || currIndex >= prices.size())
            return 0;
        if (dp[currIndex][canBuy][transactionCount] != -1)
            return dp[currIndex][canBuy][transactionCount];
        if (canBuy == 1)
        {
            int idle = Profit(currIndex + 1, canBuy, transactionCount, prices, dp);
            int buy = -prices[currIndex] + Profit(currIndex + 1, 1 - canBuy, transactionCount, prices, dp);

            return dp[currIndex][canBuy][transactionCount] = max(idle, buy);
        }
        else
        {
            int idle = Profit(currIndex + 1, canBuy, transactionCount, prices, dp);
            int sell = prices[currIndex] + Profit(currIndex + 1, 1 - canBuy, transactionCount - 1, prices, dp);
            return dp[currIndex][canBuy][transactionCount] = max(idle, sell);
        }
    }
};