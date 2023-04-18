class Solution
{
    public:
        int findPeakElement(vector<int> &nums)
        {
            int n = nums.size();
            if(n==1)
                return 0;

            nums.insert(nums.begin(), INT_MIN);

            nums.push_back(INT_MIN);
            int start = 1;
            int end = n ;
            
            

            while (start <= end)
            {
                int mid = (start + end) / 2;
                

                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                {
                   
                    return mid-1;
                }

                if (nums[mid - 1] > nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            return start-1;
        }
};