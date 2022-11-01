//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
     
    bool isCyclic(int V, vector<int> adj[]) {
      vector<bool>visited(V,false);
      vector<bool>recursiveStack(V,false);
      for(int i=0;i<V;i++)
      {
          if(visited[i]==false && DFS(i,adj,visited,recursiveStack))
               return true;
          
      }
      
      return false;
    }
    
    
    
    
    bool DFS(int currVertex,vector<int> adj[],  vector<bool>&visited,vector<bool>&recursiveStack)
    {
        
        visited[currVertex]=true;
        recursiveStack[currVertex]=true;
        
        vector<int>neigh=adj[currVertex];
        
        for(auto eachNeigh:neigh)
        {
            if(visited[eachNeigh]==false)
            {
             if(   DFS(eachNeigh,adj,visited,recursiveStack))
             return true;
            }
            else
            {
              if(  recursiveStack[eachNeigh]==true)
              return true;
            }
        }
        recursiveStack[currVertex]=false;
        return false;
    }
    
    

  
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends