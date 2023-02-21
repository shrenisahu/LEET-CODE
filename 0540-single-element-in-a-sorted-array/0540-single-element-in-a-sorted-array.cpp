class Solution
{
    public:
        int singleNonDuplicate(vector<int> &nums)
        {

            int n = nums.size();
            int start = 0;
            int end = n - 1;
            int ans = 0;
            if (n == 1)
                return nums[0];

            while (start < end)
            {

                int mid = (start + end) / 2;
                if (mid % 2 == 0 && (nums[mid]==nums[mid+1]))
                {
                start = mid+1;
                }
                else if (mid % 2 == 1 && (nums[mid]==nums[mid-1]))
                {
                    start = mid+1;
                }
                else 
                         end=mid;
            }

            return nums[start];
        }
};