class Solution
{
    public:
        int combinationSum4(vector<int> &nums, int target)
        {

            int n=nums.size();
            vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
            
            int currSum = target;
            int currIndex = 0;
            return findCombination(currIndex, currSum,  nums, dp);
        }

    int findCombination(int currIndex, int currSum,  vector<int> &nums,   vector<vector<int>>&dp)
    {
        if (currSum == 0)
        {
          
                return 1;
        }

        if (currIndex >= nums.size())
            return 0;
        if(dp[currSum][currIndex]!=-1)
            return dp[currSum][currIndex];
        int consider = 0;
        int notConsider = findCombination(currIndex + 1, currSum, nums, dp);
        if (currSum >= nums[currIndex])
        {
            

            consider = findCombination(0, currSum - nums[currIndex], nums, dp);
        }
       

        return dp[currSum][currIndex]=consider + notConsider;
    }
};