class Solution
{
    int maxCycleLength = -1;
    public:
        int longestCycle(vector<int> &edges)
        {
            int n = edges.size();

            vector<bool> visited(n, false);

            for (int currVertex = 0; currVertex < n; currVertex++)
            {

                if (visited[currVertex] == false)
                {
                    vector<int> store;
                    DFS(currVertex, visited, store, edges);
                }
            }

            return maxCycleLength;
        }

    void DFS(int currVertex,vector<bool> &visited,vector<int>&store,vector<int> &edges)
    {
        if (currVertex == -1) return;

        if (visited[currVertex])
        {
           int  count = -1;
            for (int i = 0; i < store.size(); i++)
            {
                if (store[i] == currVertex)
                {
                    count = i;
                    break;

                }
            }

            if (count == -1)
                return;
            int num=store.size() - count;
            maxCycleLength = max(maxCycleLength, num);
            return;
        }

        visited[currVertex] = true;
        store.push_back(currVertex);
        DFS(edges[currVertex], visited, store, edges);
        }
    };