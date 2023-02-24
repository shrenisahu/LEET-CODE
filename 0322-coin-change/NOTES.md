**This is a special problem because here we will not only initialize the 1st row and the first column but also we will initialize thr 2 row as well,**
​
​
​
​
​
​
​
​
​
class Solution
{
public:
int Solve(vector<int> &coins, int amount, vector<int> &dp)
{
​
if (amount == 0)
return 0;
if (dp[amount] != -1)
return dp[amount];
​
int minAns = 1000000;
for (int i = 0; i < coins.size(); i++)
{
int elem = coins[i];
int temp = 1000000;
if (amount >= coins[i])
temp = 1 + Solve(coins, amount - coins[i], dp);
minAns = min(minAns, temp);
}
​
return dp[amount] =min( minAns,notTake);
}
​
int Tabulate(vector<int> &coins, int amount)
{
int n = coins.size();
vector<int> dp(amount + 1, 1e9);
dp[0] = 0;
​
for (int j = 0; j <= amount; j++)
{
int minAns = 1e9;
for (int i = 0; i < coins.size(); i++)
{
​
int temp = 1e9;
if (j >= coins[i])
{
temp = 1 + dp[j - coins[i]];