class Solution
{
public:
int largestRectangleArea(vector<int> &heights)
{
​
int n = heights.size();
int maxArea = INT_MIN;
​
stack<int>st;
vector<int> leftMin(n);
vector<int> rightMin(n);
for (int i = 0; i < n; i++)
{
int currElem = heights[i];
while (st.empty() && heights[st.top()] >= currElem)
{
st.pop();
}
if (st.empty())
{
leftMin[i] = 0;
}
else
leftMin[i] = st.top() + 1;
​