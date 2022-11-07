class Solution
{
    public:
        vector<int> eventualSafeNodes(vector<vector < int>> &graph)
        {

            int V = graph.size();
            queue<int>que;
            vector<int>ans;
            vector<vector < int>> grid;

            for (int i = 0; i < V; i++)
            {
                vector<int> temp;
                grid.push_back(temp);
            }

            for (int i = 0; i < V; i++)
            {
                vector<int> neigh = graph[i];
                for (auto eachEdge: neigh)
                {
                    grid[eachEdge].push_back(i);
                }
            }

            vector<int> inDegree(V, 0);
            for (int i = 0; i < V; i++)
            {
                vector<int> neigh = grid[i];
                for (auto eachEdge: neigh)
                {
                    inDegree[eachEdge]++;
                }
            }
            for(int i=0;i<V;i++)
            {
                if(inDegree[i]==0)
                    que.push(i);
            }
            
            while(!que.empty())
            {
                int vertex=que.front();
                que.pop();
                ans.push_back(vertex);
                vector<int>temp=grid[vertex];
                for(auto j:temp)
                {
                    inDegree[j]--;
                    if(inDegree[j]==0)
                        que.push(j);
                }
            }
            sort(ans.begin(),ans.end());
            return ans;
        }
};