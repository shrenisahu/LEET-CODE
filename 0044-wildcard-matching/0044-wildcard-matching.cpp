class Solution
{
    public:

        bool isValid(int i, int j, string s, string p, vector<vector < int>> &dp)
        {
            if (i == 0 && j == 0)
                return true;

            if (j == 0 && i > 0)
                return false;

            if (i == 0 && j > 0)
            {

                for (int k = j; k > 0; k--)
                {
                    if (p[k - 1] != '*')
                        return false;
                }
                return true;
            }
            if (dp[i][j] != -1)
                return dp[i][j];
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                return dp[i][j] = isValid(i - 1, j - 1, s, p, dp);
            }
            if (p[j - 1] == '*')
            {

                bool takeStarAsEmpty = isValid(i - 1, j, s, p, dp);
                bool takeStarAsNotEmpty = isValid(i, j - 1, s, p, dp);

                return dp[i][j] = takeStarAsEmpty | takeStarAsNotEmpty;
            }

            return dp[i][j] = false;
        }

    bool Tabulate(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector < bool>> dp(m + 1, vector<bool> (n + 1, 0));

        dp[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= n; j++)
        {
            bool flag = true;

            for (int k = j; k > 0; k--)
            {
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
bool isAllStars(string & S1, int i) {

 
  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}
    bool spaceOpt(string s, string p)
    {
        // int m = s.size();
        // int n = p.size();
          int n = s.size();
        int m = p.size();

        vector<bool> dp(n + 1, 0), temp(n + 1, 0);
        dp[0] = 1;
      
      

        for (int i = 1; i <= m; i++)
        {

            temp[0] = isAllStars(p,i);


            for (int j = 1; j <= n; j++)
            {
                if (s[j - 1] == p[i - 1] || p[i - 1] == '?')
                {
                    temp[j] = dp[j - 1];
                }
                else if (p[i - 1] == '*')
                {
                    temp[j] = dp[j] || temp[j - 1];
                }
                else temp[j] = false;
            }
            dp = temp;
        }
        return dp[n];
    }

    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));
       	// bool ans = isValid(m, n, s, p, dp);
        bool ans = spaceOpt(s, p);
        return ans;
    }
};