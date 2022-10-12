class Solution
{
    public:
        bool increasingTriplet(vector<int> &nums)
        {

            int n = nums.size();
            int firstSmallNum = INT_MAX;
            int secondsmallNum = INT_MAX;

            for (int i = 0; i < n; i++)
            {
                if (firstSmallNum >= nums[i])
                {
                    firstSmallNum = nums[i];
                }
                else if (secondsmallNum >= nums[i])
                {
                    secondsmallNum = nums[i];
                }
                else
                    return true;
            }
            return false;
        }
        };