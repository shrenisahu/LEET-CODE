class Solution
{
    public:
        bool isPossible(vector<int> &nums, int index, int targetSum, int n, unordered_map<string, bool> &mymap)
        {
            if (targetSum == 0) return true;
            if (index >= n) return false;
            string key = to_string(index) + "-" + to_string(targetSum);
            if (mymap.find(key) != mymap.end()) return mymap[key];
            bool consider = false;
            if (nums[index] <= targetSum)
            {
                consider = isPossible(nums, index + 1, targetSum - nums[index], n, mymap);
            }
            if (consider)
            {
                // mymap[key] = consider;
                return true;
            }
            bool notConsider = isPossible(nums, index + 1, targetSum, n, mymap);
            mymap[key] = consider || notConsider;
            return consider || notConsider;
        }
    bool canPartition(vector<int> &nums)
    {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        if (totalsum % 2 != 0) return false;
        unordered_map<string, bool> mymap;
        return isPossible(nums, 0, totalsum / 2, nums.size(), mymap);
    }
};