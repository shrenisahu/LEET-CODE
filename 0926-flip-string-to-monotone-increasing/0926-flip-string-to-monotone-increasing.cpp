class Solution {
public:
    int helper(int i, int prev, string &s, int n, vector<vector<int>> &dp){
        if(i>=n) return 0;

        if(dp[i][prev] != -1) return dp[i][prev];

        int ans = INT_MAX;

        if(s[i]=='0'){
            if(prev == 0){
                ans = min(ans,min(1 + helper(i+1,1,s,n,dp), helper(i+1,0,s,n,dp)));
            }else{
                ans = 1 + helper(i+1,1,s,n,dp);
            }
        }else {
            if(prev == 0){
                ans = min(ans,min(1 + helper(i+1,0,s,n,dp), helper(i+1,1,s,n,dp)));
            }else{
                ans = helper(i+1,1,s,n,dp);
            }
        }

        return dp[i][prev] = ans;
    }

    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (2,-1));

        int res = helper(0,0,s,n,dp);
        return res;
    }
};