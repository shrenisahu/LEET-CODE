class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        int maxProfit=0;
        int maxTillNow=INT_MIN;
        
        for(int i=n-2;i>=0;i--)
        {
            maxTillNow=max(maxTillNow,prices[i+1]);
            maxProfit=max(maxProfit,maxTillNow-prices[i]);
        }
        
        return maxProfit;
        
        
    }
};