class Solution
{
    public:
        int findCheapestPrice(int n, vector<vector < int>> &flights, int src, int dst, int k)
        {

            vector<vector<vector< int>>> adj = createGraph(n, flights);
            vector<int> distance(n, 1e9);
            queue<vector < int>> que;

            que.push({ 0,
                src,
                0 });
            distance[src] = 0;

            while (!que.empty())
            {

                auto currVec = que.front();
                que.pop();
                int stopCount = currVec[0];

                int vertex = currVec[1];
                int cost = currVec[2];

                if (stopCount > k )
                    continue;

                vector<vector < int>> neigh = adj[vertex];
                for (auto it: neigh)
                {

                    int newVertex = it[0];
                    int newCost = it[1];

                    if (distance[newVertex] > cost + newCost && stopCount <= k)
                    {
                        distance[newVertex] = cost + newCost;
                        que.push({ stopCount + 1,
                            newVertex,
                            cost + newCost });
                    }
                }
            }

            if (distance[dst] == 1e9)
                return -1;

            return distance[dst];
        }

    vector<vector<vector< int>>> createGraph(int V, vector<vector < int>> &adj)
    {

        vector<vector<vector< int>>> graph;

        for (int i = 0; i < V; i++)
        {
            vector<vector < int>> arr;
            graph.push_back(arr);
        }
        for (auto it: adj)
        {
            int src = it[0];
            int dest = it[1];
            int wt = it[2];

            vector<int> temp;
            temp.push_back(dest);
            temp.push_back(wt);
            graph[src].push_back(temp);
        }

        return graph;
    }
};