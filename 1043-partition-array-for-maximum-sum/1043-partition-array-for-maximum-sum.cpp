class Solution
{
    public:
        int mod=1e9+7;
        int solve(int start, int k, vector<int> &arr ,  vector<int>&dp)
        {
            int n=arr.size();

            if (start == arr.size())
                return 0;
if(dp[start]!=-1)
    return dp[start];
            int len = 0;
            int currMax = INT_MIN;
            int maxSum = INT_MIN;
            int temp = min(start + k, n);
            for (int j = start; j < temp; j++)
            {

                len++;
                currMax = max(currMax, arr[j]);
                int sum = ((len *currMax)%mod) + solve(j + 1, k, arr,dp);
                maxSum = max(maxSum, sum);
            }

            return dp[start]= maxSum;
        }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        int ans = solve(0, k, arr ,dp);
        return ans;
    }
};