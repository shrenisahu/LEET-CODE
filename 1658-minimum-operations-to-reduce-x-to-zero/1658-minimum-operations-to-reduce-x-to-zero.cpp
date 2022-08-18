class Solution
{
    public:
        int minOperations(vector<int> &nums, int x)
        {

            int totalSum = 0;
            for (auto eachNum: nums)
            {
                totalSum += eachNum;
            }

            int target = totalSum - x;
            if (target == 0)
                return nums.size();
            int ans = largestSubArray(nums, target);
            cout << target << "  " << ans;
            if (ans == 0)
                return -1;
            return nums.size() - ans;
        }

    int largestSubArray(vector<int> &nums, int target)
    {

        int Sum = 0;
        int maxLength = 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            Sum += nums[i];

            if (mpp.find(Sum) == mpp.end())
            {
                mpp[Sum] = i;
            }

            if (mpp.find(Sum - target) != mpp.end())
            {
                maxLength = max(maxLength, i - mpp[Sum - target]);
                cout << maxLength << "  ";
            }
        }

        for (auto temp: mpp)
        {
           	// cout<<temp.first<<"  "<<temp.second<<endl;
        }
        return maxLength;
    }
};