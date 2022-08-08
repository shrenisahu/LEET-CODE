class Solution
{
    public:
        int longestIdealString(string s, int k)
        {
            vector<vector < int>> dp(s.size() + 1, vector<int> (150, -1));

            int currVal = 0;
            int currIndex = 0;

            return LongestString(currIndex, currVal, s, k, dp);
        }

    int LongestString(int currIndex, int currVal, string &s, int& k, vector<vector < int>> &dp)
    {

        if (currIndex >= s.size())
            return 0;
        if (dp[currIndex][currVal] != -1)
            return dp[currIndex][currVal];

        int consider = 0, notConsider = 0;
        if (currVal == 0 || abs(s[currIndex] - currVal) <= k)
            consider = 1 + LongestString(currIndex + 1, s[currIndex], s, k, dp);
        notConsider = LongestString(currIndex + 1, currVal, s, k, dp);

        return dp[currIndex][currVal] = max(consider, notConsider);
    }
};