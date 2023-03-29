class Solution
{
public:
​
bool isPalindrome(int start, int end, string &s)
{
​
while (start <= end)
{
if (s[start] != s[end])
return false;
​
start++;
end--;
}
return true;
}
​
int Solve(int i, int j, string &s, vector<vector < int>> &dp)
{
if (isPalindrome(i, j, s))
return 0;
if (dp[i][j] != -1)
return dp[i][j];
int ways = 10000;
for (int k = i; k <= j - 1; k++)
{
​
int currAns = 1 + Solve(i, k, s, dp) + Solve(k + 1, j, s, dp);
ways = min(ways, currAns);
}
return dp[i][j] = ways;
}
​
int Tabulate(string s)
{
int N = s.size();
vector<vector < int>> dp(N, vector<int> (N, 10000));
for (int i = 0; i < N; i++)
{
for (int j = 0; j < N; j++)
{
if (isPalindrome(i, j, s))
dp[i][j] = 0;