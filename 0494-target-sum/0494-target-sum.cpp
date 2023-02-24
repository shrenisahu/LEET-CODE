class Solution
{
    public:

        int Solve(int idx, int target, vector<int> &nums)
        {
            if (idx == nums.size() && target == 0)
                return 1;
            if (idx == nums.size())
                return 0;

            
           
            int takePlus = Solve(idx + 1, target - nums[idx], nums);
            int takeMinus = Solve(idx + 1, target + nums[idx], nums);

            return takePlus + takeMinus;
        }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<string, int> mpp;
        int ans = Solve(0, target, nums);

        return ans;
    }
};