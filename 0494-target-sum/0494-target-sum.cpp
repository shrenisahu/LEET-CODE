class Solution
{
    public:

        int Solve(int idx, int target, vector<int> &nums, unordered_map<string, int> &mpp)
        {
            if (idx == nums.size() && target == 0)
                return 1;
            if (idx == nums.size())
                return 0;

            string currStr = to_string(idx) + "-" + to_string(target);
            if (mpp.find(currStr) != mpp.end())
                return mpp[currStr];
            int takePlus = Solve(idx + 1, target - nums[idx], nums, mpp);
            int takeMinus = Solve(idx + 1, target + nums[idx], nums, mpp);

            return mpp[currStr] = takePlus + takeMinus;
        }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<string, int> mpp;
        int ans = Solve(0, target, nums, mpp);

        return ans;
    }
};