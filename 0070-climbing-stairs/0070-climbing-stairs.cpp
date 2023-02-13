class Solution
{
    public:

        int countWays(int steps, vector<int> &dp)
        {
            if (steps == 0)
                return 1;
            if (dp[steps] != -1)
                return dp[steps];

            int twoSteps = 0;
            int oneStep = countWays(steps - 1,dp);

            if (steps > 1)
                twoSteps = countWays(steps - 2,dp);

            return dp[steps] = oneStep + twoSteps;
        }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        int answer = countWays(n, dp);

        return answer;
    }
};