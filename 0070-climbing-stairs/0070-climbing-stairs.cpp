class Solution
{
    public:

        int countWays(int steps, vector<int> &dp)
        {
            if (steps <= 0)
                return dp[steps] = 1;
            if (dp[steps] != -1)
                return dp[steps];
            int twoSteps = 0;
            int oneStep = countWays(steps - 1, dp);
            if (steps - 2 >= 0)
                twoSteps = countWays(steps - 2, dp);

           	// int ans=0;
           	// for(int i=1;i<=2;i++)
           	// {
           	//     int temp=countWays(steps - i, dp);
           	//     ans+=temp;
           	// }
            return dp[steps] = oneStep + twoSteps;
           	// return dp[steps] = ans;
        }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        int answer = countWays(n, dp);

        return answer;
    }
};