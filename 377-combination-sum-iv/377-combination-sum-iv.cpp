class Solution
{
    public:
        int combinationSum4(vector<int> &nums, int target)
        {
            int n = target;
            vector<int> dp(n + 1, -1);
            return PossibleCombo(target, nums, dp);
        }

    int PossibleCombo(int target, vector<int> &nums, vector<int> &dp)
    {
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;
if(dp[target]!=-1)
    return dp[target];
        int ans = 0;
        for (auto i: nums)
            ans += PossibleCombo(target - i, nums, dp);

        return dp[target]=ans;
    }
};