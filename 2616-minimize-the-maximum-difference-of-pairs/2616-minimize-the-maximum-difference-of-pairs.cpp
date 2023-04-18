class Solution
{
    public:

        bool isPossible(vector<int> &nums, int p, int diff)
        {
            int n = nums.size();

            for (int i = 0; i < n - 1; i++)
            {

                if (abs(nums[i] - nums[i + 1]) <= diff)
                {
                    p--;
                    i++;
                }

                if (p == 0)
                    return true;
            }

            return false;
        }

    int minimizeMax(vector<int> &nums, int p)
    {
        if(p==0)
            return 0;

        sort(nums.begin(), nums.end());
        int minAns = 0;

        int start = 0;
        int end = nums.back() - nums.front();

        while (start <= end)
        {

            int mid = (end + start )/ 2;
            if (isPossible(nums, p, mid))
            {
                minAns = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        return minAns;
    }
};