class Solution
{
    public:
        bool checkForStars(string pattern, int j)
        {
            if (pattern[j] != '*')
            {
                cout << "here";
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
            return true;

        if (j == 0 && i > 0)
            return false;

        if (i == 0 && j > 0)
        {
            return checkForStars(pattern, j - 1);
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

//     bool Tabulate(string str, string pattern)
//     {
//         int m = str.size();
//         int n = pattern.size();
//         vector<vector < int>> dp(m + 1, vector<int> (n + 1, 0));
//         dp[0][0]=1;
//         for(int i=1;i<=m;i++)
//         {
//             dp[i][0]=0;
//         }
//         for(int j=1;j<=n;j++)
//         {
//             dp[]
            
//         }
//     }

    bool isMatch(string str, string pattern)
    {
        int m = str.size();
        int n = pattern.size();
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));
        bool ans = isValid(m, n, str, pattern, dp);

        return ans;
    }
};