class Solution
{
public:
long long totalCost(vector<int> &nums, int k, int candidates)
{
typedef pair<int, int> pi;
long long ans = 0;
int n = nums.size();
priority_queue<pi, vector < pi>, greater < pi>> pqFirst;
priority_queue<pi, vector < pi>, greater < pi>> pqSecond;
unordered_set<int> stt;
int i = 0;
int j = n - 1;
int count = 0;
​
while (count <k)
{
while (pqFirst.size() < candidates && i<n)
{
if (stt.find(i) == stt.end())
{
cout<<"-)"<<nums[i]<<" "<<i<<endl;
pqFirst.push(make_pair(nums[i],
i));
i++;
}
}
while (pqSecond.size() < candidates && j>=0)
{
if (stt.find(j) == stt.end())
{
cout<<"-:"<<nums[j]<<" "<<j<<endl;
pqSecond.push(make_pair(nums[j],
j));
j--;
}
}
while(stt.find(pqFirst.top().second) !=stt.end())
{
pqFirst.pop();