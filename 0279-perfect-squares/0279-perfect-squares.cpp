class Solution
{

    public:
        int findSquare(int currNum, vector<int> &dp)
        {
            if (currNum == 0)
                return 0;

            if (dp[currNum] != -1)
                return dp[currNum];

            int ans = INT_MAX;
            for (int i = 1; i <= 100; i++)
            {
                if (i * i <= currNum)
                {
                    int tempAns = 1 + findSquare(currNum - (i *i), dp);
                    ans = min(ans, tempAns);
                }
            }

            return dp[currNum] = ans;
        }

    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        int ans = findSquare(n, dp);
        return ans;
    }
};