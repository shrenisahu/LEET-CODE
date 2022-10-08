class Solution
{
    public:
        int threeSumClosest(vector<int> &nums, int target)
        {
            int n = nums.size() - 1;
            sort(nums.begin(), nums.end());
            int currDiff = INT_MAX;
            int currSum = 0;
            for (int i = 0; i < nums.size() - 2; i++)
            {
                cout << i << "  ";
                int j = i + 1;
                int k = n;

                while (j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];

                    

                        if (abs(sum - target) < currDiff)
                        {

                            currDiff = abs(sum - target);
                            currSum = sum;
                        }

                    if (sum == target)
                        return sum;
                    if (sum > target)
                    {
                        k--;
                    }
                    else
                    {
                        j++;
                    }
                }
            }

            return currSum;
        }
};