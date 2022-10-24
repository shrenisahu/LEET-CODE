class Solution
{
    public:
        int findCircleNum(vector<vector < int>> &isConnected)
        {
            int V = isConnected.size();
            vector<bool> visited(V + 1, false);
            int count = 0;
            for (int i = 0; i < V; i++)
            {

                if (visited[i] == false)
                {
                    BFS(i, V, isConnected, visited);
                    count++;
                }
            }

            return count;
        }

    void BFS(int currVertex, int V, vector<vector < int>> &isConnected, vector< bool > &visited)
    {

        queue<int>que;
        que.push(currVertex);
        
        while(!que.empty())
        {
            int vertex=que.front();
            que.pop();
            
            if(visited[vertex]==true)
                continue;
            visited[vertex]=true;
            
            for(int i=0;i<V;i++)
            {
                if(isConnected[vertex][i]==1)
                {
                    que.push(i);
                }
            }
        }
       
    }
};