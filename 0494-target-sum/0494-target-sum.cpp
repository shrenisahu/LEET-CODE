class Solution
{
    public:

        int Solve(int idx, int target, vector<int> &nums, vector<vector< int>> &dp)
        {

            if (idx >= nums.size())
            {
                return target == 0;
            }
            if (dp[idx][target] != -1)
                return dp[idx][target];
            int notTake = Solve(idx + 1, target, nums, dp);
            int take = 0;
            if (target >= nums[idx])
                take = Solve(idx + 1, target - nums[idx], nums, dp);

            return dp[idx][target] = take + notTake;
        }

    int Tabulate(vector<int> &nums, int currTarget)
    {
        int n = nums.size();
      
        vector < int>dp(currTarget+ 2, 0);
      
        dp[0] = 1;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            vector < int> temp(currTarget + 1);
            for (int sum = 0; sum <= currTarget; sum++)
            {
                int notTake = dp[sum];
                int take = 0;
                if (sum >= nums[idx])
                    take = dp[sum - nums[idx]];

                temp[sum] = take + notTake;
            }
            dp = temp;
        }

        return dp[currTarget];
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

        if (totalSum < abs(target))
            return 0;

        int currTarget = (totalSum + target) / 2;
        vector<vector < int>> dp(n + 2, vector<int> (currTarget + 1, -1));
       	// int ans = 0;
       	// int ans = Solve(0, currTarget, nums,dp);
        int ans = Tabulate(nums, currTarget);
        return ans;
    }
};