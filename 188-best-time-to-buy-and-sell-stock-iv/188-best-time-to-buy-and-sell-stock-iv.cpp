class Solution
{
    public:
        int maxProfit(int k,vector<int> &prices)
        {
            int n=prices.size()+1;
            vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(3,-1)));
            int transCount = 2;
            int currIndex = 0;
            return maximizeProfit(0,1,k,prices,dp);
        }

    int maximizeProfit(int currIndex, int canBuy, int transCount, vector<int> &prices , vector<vector<vector<int>>>&dp)
    {
        if (transCount == 0 || currIndex >= prices.size())
            return 0;
if(dp[currIndex][transCount][canBuy]!=-1)
    return dp[currIndex][transCount][canBuy];
        if (canBuy)
        {
            int idle = maximizeProfit(currIndex + 1, canBuy, transCount, prices ,dp);
            int buy = -prices[currIndex] + maximizeProfit(currIndex + 1, 1 - canBuy, transCount, prices ,dp);
            return dp[currIndex][transCount][canBuy]= max(idle, buy);
        }
        else
        {
            int idle = maximizeProfit(currIndex + 1, canBuy, transCount, prices ,dp);
            int sell = prices[currIndex] + maximizeProfit(currIndex + 1, 1, transCount - 1, prices ,dp);
            return  dp[currIndex][transCount][canBuy]=max(idle, sell);
        }
    }
};