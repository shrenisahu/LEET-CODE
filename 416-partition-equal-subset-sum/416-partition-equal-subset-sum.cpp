class Solution {
public:
    
    
    bool SubsetSum(vector<int>& nums,int currIndex,int targetSum,  vector<vector<int>> &mpp)
    {
        
        
        if(targetSum==0)
            return true;
        
        if(currIndex>=nums.size())
            return false;
        if(mpp[currIndex][targetSum]!=-1)
        return mpp[currIndex][targetSum];
        bool consider=false;
        if(nums[currIndex]<=targetSum)
            consider=SubsetSum(nums,currIndex+1,targetSum-nums[currIndex],mpp);
        
        
    bool  notConsider=SubsetSum(nums,currIndex+1,targetSum,mpp);
        mpp[currIndex][targetSum]=consider|| notConsider;
        
        return  mpp[currIndex][targetSum];
        
    }
    
    
    bool canPartition(vector<int>& nums) {
        
        unordered_map<string,int>mpp;
      int n=nums.size();
             
        int sum=0;
        for(auto b:nums)
            sum+=b;
         vector<vector<int>> dp(n+1, vector<int>((sum/2) + 1, -1));
        if(sum%2!=0)
            return false;
        
        else return SubsetSum(nums,0,sum/2,dp);
        
    }
};