class Solution
{
    public:

        bool Solve(int idx, int targetSum, vector<int> &nums, unordered_map<string, bool> &mpp)
        {

            if (targetSum==0)
                return true;

            if (idx >= nums.size()) return false;

            string currStr = to_string(idx) + "+" + to_string(targetSum);
            if (mpp.find(currStr) != mpp.end())
                return mpp[currStr];

            bool take = false;

            if (nums[idx] <= targetSum)
                take = Solve(idx + 1, targetSum - nums[idx], nums, mpp);
            if (take)
            {
                 mpp[currStr] = true;
                return true;
            }

            bool notTake = Solve(idx + 1, targetSum, nums, mpp);

            mpp[currStr] = take || notTake;

            return take || notTake;;
        }

    bool Tabulate(vector<int> &nums, int targetSum)
    {
        int n = nums.size();

        vector<int> dp(targetSum + 1, 0);

        dp[targetSum] = 1;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            vector<int> temp(targetSum + 1, 0);
            for (int currSum = targetSum; currSum >= 0; currSum--)
            {
                bool notTake = dp[currSum];
                bool take = false;
                if (nums[idx] + currSum <= targetSum)
                    take = dp[nums[idx] + currSum];

                temp[currSum] = take || notTake;
            }
            dp = temp;
        }

        return dp[0];
    }

    bool canPartition(vector<int> &nums)
    {
        unordered_map<string, bool> mpp;
        int n = nums.size();
        int sum = 0;
        for (auto &i: nums)
            sum += i;

        if (sum % 2 == 1)
            return false;
        int targetSum = sum / 2;

        vector<vector < int>> dp(n + 1, vector<int> (targetSum + 1, -1));
        bool ans = Solve(0, targetSum, nums, mpp);

       	// bool ans = Tabulate(nums, targetSum);

        return ans;
    }
};