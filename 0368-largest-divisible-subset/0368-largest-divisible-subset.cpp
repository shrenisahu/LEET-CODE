class Solution
{
    public:
        vector<int> largestDivisibleSubset(vector<int> &nums)
        {
            vector<int> ans;
            sort(nums.begin(), nums.end());
            int n = nums.size();
            vector<int> dp(n, 1);
            vector<int> hash(n);

            int maxTillNow = 1;
            int maxIndex = 0;
            for (int i = 0; i < n; i++)
                hash[i] = i;

            for (int i = 1; i < n; i++)
            {
                for (int prev = 0; prev < i; prev++)
                {

                    if (nums[i] % nums[prev] == 0)
                    {
                        if (dp[i] < 1 + dp[prev])
                        {
                            dp[i] = 1 + dp[prev];
                            hash[i] = prev;
                        }
                    }
                }
                if (dp[i] > maxTillNow)
                {
                    maxTillNow = dp[i];
                    maxIndex = i;
                }
            }
            ans.push_back(nums[maxIndex]);
            
            while(hash[maxIndex]!=maxIndex)
            {
                ans.push_back(nums[hash[maxIndex]]);
                maxIndex=hash[maxIndex];
            }

            return ans;
        }
};