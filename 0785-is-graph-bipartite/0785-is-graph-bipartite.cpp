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
                bool ans = DFS(i, graph, visited,0);
                if (ans == false)
                    return false;
            }
            return true;
        }

   bool DFS(int vertex,vector<vector < int>> &graph,vector<int>&visited,int currColor)
   {

       visited[vertex]=currColor;
       
       vector<int>neigh=graph[vertex];
       for(auto eachEdge:neigh)
       {
           if(visited[eachEdge]==-1)
           {
              if( DFS(eachEdge,graph,visited,1-currColor)== false)
                  return false;
           }
           else
           {
               if(visited[eachEdge]==currColor)
                   return false;
           }
           
          
       }
        return true;
   }
};