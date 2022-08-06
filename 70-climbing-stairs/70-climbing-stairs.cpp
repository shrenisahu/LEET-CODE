class Solution
{
    public:
        int climbStairs(int n)
        {
            vector<int>dp(n+1,-1);
            return countSteps(n,dp);
        }

    int countSteps(int target, vector<int>&dp)
    {
         
        if (target == 0)
            return 1;
       if (target < 0)
            return 0;
     if(dp[target]!=-1)
         return dp[target];
        int ans1=0;
        int ans2=0;
        // if(target >=1)
            ans1=countSteps(target - 1,dp);
        // if(target >=2)
            ans2=countSteps(target - 2,dp);
            
        return dp[target]= ans1+ans2;
    }
};