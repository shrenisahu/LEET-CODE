class Solution {
public:
    
    int SolveLIS(int idx,int prev_idx,vector<int>& nums, vector<vector<int>>&dp)
    {
        
        if(idx==nums.size())
        {
            return 0;
        }
        
        if(dp[idx][prev_idx+1]!=-1)
            return dp[idx][prev_idx+1];
        int notTake=SolveLIS(idx+1,prev_idx,nums,dp);
         int take=0;
        
        if(prev_idx==-1||nums[idx] >nums[prev_idx])
        {
             take=1+SolveLIS(idx+1,idx,nums,dp);
        }
        
        return dp[idx][prev_idx+1]= max(notTake,take);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=SolveLIS(0,-1,nums,dp);
        return ans;
        
    }
};