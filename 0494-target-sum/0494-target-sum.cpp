class Solution
{
    public:

        int Solve(int idx, int target, vector<int> &nums,  vector<vector<int>>&dp)
        {

            if (idx >=nums.size())
            {
                return target == 0;
            }
            if(dp[idx][target]!=-1)
                return dp[idx][target];
            int notTake = Solve(idx + 1, target, nums,dp);
            int take = 0;
            if (target >= nums[idx])
                take = Solve(idx + 1, target - nums[idx], nums,dp);

            return  dp[idx][target]=take + notTake;
        }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int totalSum = 0;
        for (auto &i: nums)
        {
            totalSum += i;
        }

        if ((totalSum + target) % 2 == 1)

            return 0;
        
        if(totalSum<abs(target))
              return 0;

        int currTarget = (totalSum + target) / 2;
        vector<vector<int>>dp(n+2,vector<int>(currTarget+1,-1));
        // int ans = 0;
       	int ans = Solve(0, currTarget, nums,dp);
        return ans;
    }
};