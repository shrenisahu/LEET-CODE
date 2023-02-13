class Solution
{
    public:

        int countWays(int steps, vector<int> &dp)
        {
            if (steps <=1)
                return 1;
            if (dp[steps] != -1)
                return dp[steps];

            int oneStep = countWays(steps - 1, dp);

            int twoSteps = countWays(steps - 2, dp);

            return dp[steps] = oneStep + twoSteps;
        }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        int answer = countWays(n, dp);

        return answer;
    }
};