class Solution
{
    public:

        int jump(vector<int> &nums)
        {
            int n=nums.size();
            vector<int>dp(n+1,-1);
            int ans = Solve(0, nums,dp);
            return ans;
        }

    int Solve(int currIdx, vector<int> &nums, vector<int>&dp)
    {
        if (currIdx >= nums.size() - 1)
        {

            return 0;
        }
        if(dp[currIdx]!=-1)
            return dp[currIdx];
        int ans = 10001;
        for (int i = 1; i <= nums[currIdx]; i++)
        {
            int temp = 1 + Solve(currIdx + i, nums,dp);
            ans = min(temp, ans);
        }

        return dp[currIdx]=ans;
    }
};