class Solution
{
    public:

        int SolveLIS(int idx, int prev_idx, vector<int> &nums, vector<vector< int>> &dp)
        {

            if (idx == nums.size())
            {
                return 0;
            }

            if (dp[idx][prev_idx + 1] != -1)
                return dp[idx][prev_idx + 1];
            int notTake = SolveLIS(idx + 1, prev_idx, nums, dp);
            int take = 0;

            if (prev_idx == -1 || nums[idx] > nums[prev_idx])
            {
                take = 1 + SolveLIS(idx + 1, idx, nums, dp);
            }

            return dp[idx][prev_idx + 1] = max(notTake, take);
        }
    int Tabulate(vector<int> &nums)
    {
        int n = nums.size();
        // vector<vector < int>> dp(n + 1, vector<int> (n + 1, 0));
        vector<int> dp(n + 1, 0), next(n + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
            {
                int notTake = dp[prev_idx + 1];
                int take = 0;

                if (prev_idx == -1 || nums[idx] > nums[prev_idx])
                {
                    take = 1 + dp[idx + 1];
                }

                next[prev_idx + 1] = max(notTake, take);
            }
            
            dp = next;
        }

        return dp[0];
    }
    
    
    int method2(vector<int> &nums)
   {
        int n = nums.size();
       
        int maxTillNow=1;
      
        vector<int> dp(n + 1, 1);
        
        for (int idx = 1; idx <n; idx++)
        {
            for (int prev_idx = 0; prev_idx <idx; prev_idx++)
            {
                if(nums[idx]>nums[prev_idx])
                dp[idx]=max(dp[idx],1+dp[prev_idx]);
            }
            
            maxTillNow=max(maxTillNow,dp[idx]);
        }

        return maxTillNow;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, -1));
       	// int ans = SolveLIS(0, -1, nums, dp);
        // int ans = Tabulate(nums);
         int ans = method2(nums);
        return ans;
    }
};