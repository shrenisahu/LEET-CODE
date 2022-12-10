class Solution
{
public:
int makeConnected(int n, vector<vector < int>> &connections)
{
int ans = 0;
int roughEdge = 0;
​
int noOfEdges = noOfEdges.size();
if (noOfEdges < n - 1)
return -1;
​
for (auto i: noOfEdges)
{
for (auto j: i)
{
int src = j[0];
int dest = j[1];
​
int parSrc = find(src);
int parDest = find(dest);
​
if (parSrc == parDest)
roughEdge++;
else union_(src,dest);
}
}
​
return ans;
}
};