class Solution
{
    public:
        bool isBipartite(vector<vector < int>> &graph)
        {
            int n = graph.size();
            vector<int> visited(n, -1);
            for (int i = 0; i < n; i++)
            {
                if (visited[i] != -1)
                    continue;
                bool ans = BFS(i, graph, visited);
                if (ans == false)
                    return false;
            }
            return true;
        }

    bool BFS(int currVeretx, vector<vector < int>> &graph, vector< int > &visited)
    {

        queue<pair<int, int>> que;
        que.push({ currVeretx,
            0 });
        while (!que.empty())
        {
            auto currPair = que.front();
            que.pop();
            int currEdge = currPair.first;
            int currColor = currPair.second;
            if (visited[currEdge] != -1)
            {
                if (visited[currEdge] != currColor)
                    return false;
            }
            else
            {
                visited[currEdge] = currColor;

            }
                vector<int> neigh = graph[currEdge];
                for (auto eachEdge: neigh)
                {
                    if(visited[eachEdge]==-1)
                    que.push({ eachEdge,
                        1 - currColor });
                }
            
        }

        return true;
    }
};