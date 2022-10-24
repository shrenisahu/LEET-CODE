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
                    DFS(i, V, isConnected, visited);
                    count++;
                }
            }

            return count;
        }

    void DFS(int currVertex, int V, vector<vector < int>> &isConnected, vector< bool > &visited)
    {

        if(visited[currVertex]==true)
            return ;
        visited[currVertex]=true;
        
        for(int i=0;i<V;i++)
        {
            if(isConnected[currVertex][i]==1)
                DFS(i,V,isConnected,visited);
        }
        return ;
    }
};