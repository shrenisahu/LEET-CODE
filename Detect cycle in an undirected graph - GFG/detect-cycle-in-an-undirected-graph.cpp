// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        for(int currVertex=0;currVertex<V;currVertex++)
        {
            if(visited[currVertex]==false)
            {
               if( DFS(currVertex,-1,visited,adj))
               return true;
            }
        }
        return false;
    }
    
    bool DFS(int currVertex,int currParent,vector<bool>&visited,vector<int> adj[])
    {
        visited[currVertex]=true;
        
        vector<int>neigh=adj[currVertex];
        
        for(auto eachNode:neigh)
        {
            if(visited[eachNode]==false)
            {
                if(DFS(eachNode,currVertex,visited,adj))
                return true;
            }
            else 
            {
                if(eachNode!=currParent)
                return true;
            }
        }
        return false;
    }
    
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends