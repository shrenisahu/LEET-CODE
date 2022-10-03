class Solution
{
    int mod = 1e9 + 7;
    unordered_map<string, int> mpp;
    public:
        int numRollsToTarget(int n, int k, int target)
        {
            // memset(dp, -1, sizeof(dp));
            return findCount(n, k, target);
        }

    int findCount(int n, int k, int target)
    {
        if (target == 0 && n == 0)
            return 1;
        if (target == 0 || n == 0)
            return 0;
        string key = to_string(n) + '-' + to_string(k) + '-' + to_string(target);
        if(mpp.find(key)!=mpp.end())
            return mpp[key];
        int ways = 0;
        for (int i = 1; i <= k; i++)
        {
            int temp = findCount(n - 1, k, target - i);
            ways = (ways % mod + temp % mod) % mod;
        }

        return mpp[key]= ways;
    }
};