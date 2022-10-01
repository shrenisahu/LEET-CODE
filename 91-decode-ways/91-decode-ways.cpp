class Solution
{
    int dp[1002];
    public:
        int numDecodings(string s)
        {
            int n = s.size();
            memset(dp, -1, sizeof(dp));
           	// memset(dp,-1,sizeof dp);
            return findDecoding(s, n, 0);
        }
    int findDecoding(string s, int n, int currIndex)
    {
        if (currIndex == n)
            return 1;
        if (currIndex > n || s[currIndex] == '0')
            return 0;
        if (dp[currIndex] != -1)
            return dp[currIndex];
        int oneJump = 0;
        int twoJump = 0;

        if (isValid(s, currIndex, currIndex))
        {
            oneJump = findDecoding(s, n, currIndex + 1);
        }
        if (isValid(s, currIndex, currIndex + 1))
        {
            twoJump = findDecoding(s, n, currIndex + 2);
        }
        return dp[currIndex] = oneJump + twoJump;
    }

    bool isValid(string &s, int start, int end)
    {

        if (s[start] == '0')
            return 0;

        string subst = s.substr(start, end - start + 1);
        int x = stoi(subst);
        cout << "  " << x;
        if (x < 27 && x > 0)
            return 1;
        else return 0;
    }
};