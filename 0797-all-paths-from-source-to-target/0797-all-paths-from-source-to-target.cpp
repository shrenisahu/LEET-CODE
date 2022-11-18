class Solution
{
    public:
    vector<vector < int>>ans;
        vector<vector < int>> allPathsSourceTarget(vector<vector < int>> &graph)
        {
            int n = graph.size();
            vector<int>path;
            DFS(0,path,graph,n);
            return ans;
        }

    void DFS(int currNode, vector<int> &path, vector<vector< int >> &graph, int n)
    {
        if (currNode == n - 1)
        {
            path.push_back(currNode);
            ans.push_back(path);
            path.pop_back();
            return ;
        }

        path.push_back(currNode);

        vector<int> neigh = graph[currNode];
        for (auto it: neigh)
        {
            DFS(it, path, graph, n);
        }

        path.pop_back();

        return;
    }
};