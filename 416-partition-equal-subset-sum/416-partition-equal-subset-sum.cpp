class Solution {
public:
    bool fUtils(vector<int> &nums, int idx, int target, vector<vector<int>> &dp)
    {
	//boundary cases
        if(idx >= nums.size() || target < 0)
        {
            return false;
        }
		//success case
        if(target == 0)
        {
            return true;
        }
		//memoisation used
        if(dp[idx][target] != -1)
        {
            return dp[idx][target];
        }
        
        //pick it
        bool pick = false;
        if(nums[idx] <= target)
        {
            pick = fUtils(nums, idx + 1, target - nums[idx], dp);
        }
        //ignore it
        bool npick = fUtils(nums, idx + 1, target, dp);
        
        return dp[idx][target] = pick || npick;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n <= 1)
        {
            return false;
        }
        
        int sum = 0;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }
        
        //if sum is odd it cant be formed
        if(sum % 2 > 0)
        {
            return false;
        }
        
        int val = sum / 2;
        
        vector<vector<int>> dp(n+1, vector<int>((sum/2) + 1, -1));//at a particular index and target can i reach or not
        
        return fUtils(nums, 0, val, dp);
    }
};