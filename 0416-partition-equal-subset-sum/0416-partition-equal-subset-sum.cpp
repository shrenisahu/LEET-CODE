class Solution
{
    public:

        bool Solve(int idx, int currSum, int targetSum, vector<int> &nums, vector<vector< int>> &dp)
        {

            if (currSum == targetSum)
                return true;

            if (idx >= nums.size()) return false;

            if (dp[idx][currSum] != -1)
                return dp[idx][currSum];

            bool notTake = Solve(idx + 1, currSum, targetSum, nums, dp);
            bool take = false;

            if (nums[idx] + currSum <= targetSum)
                take = Solve(idx + 1, nums[idx] + currSum, targetSum, nums, dp);
            return dp[idx][currSum] = take || notTake;
        }

    bool Tabulate(vector<int> &nums, int targetSum)
    {
        int n = nums.size();
        vector<vector < int>> dp(n + 1, vector<int> (targetSum + 1, 0));

        for (int i = 0; i <= n; i++)
        {

            dp[i][targetSum] = 1;
        }

        // dp[n - 1][nums[n - 1]] = 1;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int currSum = targetSum; currSum >= 0; currSum--)
            {
                bool notTake = dp[idx + 1][currSum];
                bool take = false;
                if (nums[idx] + currSum <= targetSum)
                    take = dp[idx + 1][nums[idx] + currSum];

                dp[idx][currSum] = take || notTake;
            }
        }

        return dp[0][0];
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (auto &i: nums)
            sum += i;

        if (sum % 2 == 1)
            return false;
        int targetSum = sum / 2;

        vector<vector < int>> dp(n + 1, vector<int> (targetSum + 1, -1));
       	// bool ans = Solve(0, 0, targetSum, nums, dp);

        bool ans = Tabulate(nums, targetSum);

        return ans;
    }
};

// Input: nums =[1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.