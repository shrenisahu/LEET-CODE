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
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
            {
                int notTake = dp[idx + 1][prev_idx+1];
                int take = 0;

                if (prev_idx == -1 || nums[idx] > nums[prev_idx])
                {
                    take = 1 + dp[idx + 1][ idx+1];
                }

                 dp[idx][prev_idx + 1] = max(notTake, take);
            }
        }
        
        return dp[0][0];
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, -1));
        // int ans = SolveLIS(0, -1, nums, dp);
        int ans=Tabulate(nums);
        return ans;
    }
};