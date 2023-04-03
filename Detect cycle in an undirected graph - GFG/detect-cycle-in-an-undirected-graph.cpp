//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool>visited(V,false);
        for(int vertex=0;vertex<V;vertex++)
        {
            if(visited[vertex]==false)
            {
                
                
              if(  BFS(vertex,adj,visited,V))
                return true;
            }
        }
        
        return false;
        
    }
    
    
    bool BFS(int vertex,vector<int> adj[],vector<bool>&visited,int V)
    {
        
        queue<pair<int,int>>que;
        que.push({vertex,-1});
        vector<int>parent(V,-1);
        
        while(!que.empty())
        {
            auto currPair=que.front();
            que.pop();
            int node=currPair.first;
            int par=currPair.second;
            if(visited[node]==true)
            continue;
            visited[node]=true;
            
            for(auto eachNeigh:adj[node])
            {
                if(visited[eachNeigh]==false)
                {
                que.push({eachNeigh,node});
                parent[eachNeigh]=node;
                }
                else
                {
                    if(eachNeigh!=parent[node])
                    return true;
                }
            }
            
          
        }
        
          return false;
        
        
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends