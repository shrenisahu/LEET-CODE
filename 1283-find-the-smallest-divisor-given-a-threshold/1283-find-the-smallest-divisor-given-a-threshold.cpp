class Solution
{
    public:

        bool isPossible(vector<int> &nums, int threshold, int divisor)
        {
            int n = nums.size();
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                int elem = nums[i];
                int que = elem / divisor;
                int rem = elem % divisor;

                if (rem > 0)
                    que++;
                sum += que;

                if (sum > threshold)
                    return false;
            }

            return true;
        }
    int smallestDivisor(vector<int> &nums, int threshold)
    {

        int start = 1;
        int end = 1000000;
        int ans = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (isPossible(nums, threshold, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};