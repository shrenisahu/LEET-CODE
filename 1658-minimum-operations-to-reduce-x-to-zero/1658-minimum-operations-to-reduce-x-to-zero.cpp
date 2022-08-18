class Solution
{
    public:
        int minOperations(vector<int> &nums, int x)
        {
            int mod=1000000007;

            int totalSum = 0;
            for (auto eachNum: nums)
            {
                totalSum +=eachNum;
            }

            int target = totalSum - x;
            if (target == 0)
            return nums.size();
            int maxL = -1;
            int left = 0;
            int n = nums.size();
            int currSum = 0;
            // cout<<"tar"<<target<<endl;
            for (int right = 0; right < n; right++)
            {
                currSum += nums[right];
               
               
                while (left <= right && currSum > target)
                {
                    currSum -= nums[left];
                    left+=1;
                }
                 if (currSum == target)
                {
                    maxL = max(maxL, right - left + 1);
                }

            }
            // cout<<maxL<<" ";
            if(maxL==-1)
                return -1;
            return n - maxL;
        }
};