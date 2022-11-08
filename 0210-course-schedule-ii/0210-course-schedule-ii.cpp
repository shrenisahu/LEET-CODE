class Solution
{
    public:
        vector<int> findOrder(int V, vector<vector < int>> &adj)
        {
            vector<int> inDegree(V, 0);
            vector<bool> visited(V, false);

            queue<int> que;
            vector<int> ans;

            vector<vector < int>> Graph = createGraph(V, adj);

            for (int i = 0; i < V; i++)
            {
                for (auto j: Graph[i])
                {

                    inDegree[j]++;
                }
            }

            for (int i = 0; i < V; i++)
            {
                if (inDegree[i] == 0)
                    que.push(i);
            }

            while (!que.empty())
            {
                int vertex = que.front();
                que.pop();
                // if (visited[vertex] == true)
                    // continue;
                visited[vertex] = true;
                ans.push_back(vertex);
                visited[vertex] = true;
                for (auto i: Graph[vertex])
                {
                    inDegree[i]--;
                    if (inDegree[i] == 0)
                        que.push(i);
                }
            }
            if (ans.size() != V)
                return vector < int> {};
            return ans;
        }

    vector<vector < int>> createGraph(int V, vector<vector < int>> &adj)
    {
        vector<vector < int>> Graph;
        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            Graph.push_back(temp);
        }

        for (int i = 0; i < adj.size(); i++)
        {
            int src = adj[i][1];
            int dest = adj[i][0];

            Graph[src].push_back(dest);
        }

        return Graph;
    }
};