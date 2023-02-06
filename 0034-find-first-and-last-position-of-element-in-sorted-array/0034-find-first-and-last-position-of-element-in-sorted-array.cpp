class Solution
{
    public:
    
      int findLastPos(vector<int> &nums, int target)
        {
            int n = nums.size();
            int start = 0;
            int end = n - 1;

            int LastOccurance = -1;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                if (nums[mid] == target)
                {
                    LastOccurance = mid;
                    start = mid + 1;
                }
                else if (nums[mid] > target)
                {
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }

            return LastOccurance;
        }

    

        int findFirstPos(vector<int> &nums, int target)
        {
            int n = nums.size();
            int start = 0;
            int end = n - 1;

            int firstOccurance = -1;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                if (nums[mid] == target)
                {
                    firstOccurance = mid;
                    end = mid - 1;
                }
                else if (nums[mid] > target)
                {
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }

            return firstOccurance;
        }

    vector<int> searchRange(vector<int> &nums, int target)
    {

        int n = nums.size();
        int start = 0;
        int end = n - 1;
        vector<int> ans(2,0);
        ans[0]=findFirstPos(nums,target);
        ans[1]=findLastPos(nums,target);
        
        return ans;

    }
};