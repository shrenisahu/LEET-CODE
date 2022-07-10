class Solution {
public:
    
    
    int minCost(vector<int>& cost,int n,  unordered_map<int,int>&mpp)
    {
        if(n==cost.size())
        {
            return 0;
        }
         if(n>cost.size())
        {
            return 1001;
        }
        int currKey=n;
        if(mpp.find(currKey)!=mpp.end())
            return mpp[currKey];
        
        int one=cost[n]+minCost(cost,n+1,mpp);
        int two=cost[n]+minCost(cost,n+2,mpp);
        
        mpp[currKey]=min(one,two);
        return min(one,two);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int>mpp;
        return min(minCost(cost,0,mpp),minCost(cost,1,mpp));
        
    }
};