class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mostTransaction=2;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(mostTransaction+1,-1)));
        unordered_map<string,int>mpp;
        return Profit(prices,0,1,mostTransaction,dp);
    }
    
    int Profit(vector<int>& prices,int currDay,bool canBuy,int transCount, vector<vector<vector<int>>>&dp)
        
    {
        
        
        if(transCount==0 || currDay>=prices.size())
        return 0;
        
        if(dp[currDay][canBuy][transCount]!=-1)
            return  dp[currDay][canBuy][transCount];
       
        
        if(canBuy==1)
        {
            int idle=Profit(prices,currDay+1,canBuy,transCount,dp);
            int buy=-prices[currDay] + Profit(prices,currDay+1,0,transCount,dp);
            return dp[currDay][canBuy][transCount]= max(idle,buy);
        }
        else 
        {
            int idle=Profit(prices,currDay+1,canBuy,transCount,dp);
            int sell=prices[currDay]+ Profit(prices,currDay+1,1,transCount-1,dp);
            return dp[currDay][canBuy][transCount]= max(idle,sell);
            
        }
        
        
    }
};