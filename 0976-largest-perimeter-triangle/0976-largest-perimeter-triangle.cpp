class Solution
{
    public:
        int largestPerimeter(vector<int> &nums)
        {
            int maxArea = 0;

            sort(nums.begin(), nums.end());
            reverse(nums.begin(), nums.end());

            int n = nums.size();
            for (int i = 0; i < n - 2; i++)
            {

                int a = nums[i];
                int b = nums[i + 1];
                int c = nums[i + 2];

                if (a + b <= c || b + c <= a || a + c <= b)
                    continue;

                maxArea = max(maxArea, a + b + c);
            }

            return maxArea;
        }
};