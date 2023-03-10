class Solution
{
    public:
        bool checkForStars(string pattern, int j)
        {
            if (pattern[j] != '*')
            {

                return false;
            }
            bool isCharContinous = false;
            for (int i = j; i >= 0; i = i - 1)
            {
                if (pattern[i] != '*')
                {
                    if (isCharContinous == true)
                    {

                        return false;
                    }
                    isCharContinous = true;
                }
                else
                    isCharContinous = false;
            }

            return true;
        }

    bool isValid(int i, int j, string str, string pattern, vector<vector < int>> &dp)
    {

        if (i == 0 && j == 0)
            return dp[i][j] = true;

        if (j == 0 && i > 0)
            return dp[i][j] = false;

        if (i == 0 && j > 0)
        {
            return dp[i][j] = checkForStars(pattern, j - 1);
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.')
        {
            return dp[i][j] = isValid(i - 1, j - 1, str, pattern, dp);
        }
        else if (pattern[j - 1] == '*')
        {
            bool zeroOccurence = isValid(i, j - 2, str, pattern, dp);
            bool morOccurence = false;
            if (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.')
            {

                morOccurence = isValid(i - 1, j, str, pattern, dp);
            }
            return dp[i][j] = zeroOccurence || morOccurence;
        }
        else
            return dp[i][j] = false;
    }

    bool Tabulate(string str, string pattern)
    {
        int m = str.size();
        int n = pattern.size();
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= n; j++)
        {
            dp[0][j] = checkForStars(pattern, j - 1);
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (pattern[j - 1] == '*')
                {

                    bool zeroOcc = dp[i][j - 2];
                    bool moreOcc = false;
                    if (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.')
                    {
                        moreOcc = dp[i - 1][j];
                    }
                    dp[i][j] = zeroOcc || moreOcc;
                }
                else dp[i][j] = false;
            }
        }
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << dp[i][j] << "  ";
            }
            cout << endl;
        }

        return dp[m][n];
    }
       bool spaceOpt(string str, string pattern)
    {
        int m = str.size();
        int n = pattern.size();
        // vector<vector < int>> dp(m + 1, vector<int> (n + 1, 0));
           vector < int> dp(n + 1, 0),temp(n+1,0);
        dp[0] = 1;
        // for (int i = 1; i <= m; i++)
        // {
        //     dp[i][0] = 0;
        // }
        for (int j = 1; j <= n; j++)
        {
            dp[j] = checkForStars(pattern, j - 1);
        }

        for (int i = 1; i <= m; i++)
        {
            temp[0]=0;
            for (int j = 1; j <= n; j++)
            {

                if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.')
                    temp[j] = dp[j - 1];
                else if (pattern[j - 1] == '*')
                {

                    bool zeroOcc = temp[j - 2];
                    bool moreOcc = false;
                    if (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.')
                    {
                        moreOcc = dp[j];
                    }
                    temp[j] = zeroOcc || moreOcc;
                }
                else temp[j] = false;
            }
            dp=temp;
        }
      
        return dp[n];
    }

    bool isMatch(string str, string pattern)
    {
        int m = str.size();
        int n = pattern.size();
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));
       	// bool ans = isValid(m, n, str, pattern, dp);
        bool ans = spaceOpt(str, pattern);

        return ans;
    }
};