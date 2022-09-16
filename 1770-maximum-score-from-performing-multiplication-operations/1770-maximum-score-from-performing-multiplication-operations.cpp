class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m=multipliers.size();
        int n=nums.size();
        int currIteration=0;
        int start=0;
        int end=m-1;
        vector<vector<int>>dp(m+1,vector<int>(m+1,INT_MIN));
        
        return findMax(start,currIteration,nums,multipliers,dp);
    }
    
    int findMax(int start,int currIteration,vector<int>& nums, vector<int>& multipliers,  vector<vector<int>>&dp)
    {
        if(currIteration ==multipliers.size())
             return 0;
        
        if(dp[start][currIteration]!=INT_MIN)
            return dp[start][currIteration];
        int considerStart=findMax(start+1,currIteration+1,nums,multipliers ,dp)+multipliers[currIteration]* nums[start];
        int considerEnd=findMax(start,currIteration+1,nums,multipliers ,dp)+multipliers[currIteration]* nums[(nums.size()-1)-(currIteration-start)];
        
        
        return  dp[start][currIteration]=max(considerStart,considerEnd);
    }
};