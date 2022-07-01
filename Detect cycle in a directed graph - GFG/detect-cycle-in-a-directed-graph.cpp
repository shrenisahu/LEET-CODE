// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited(V,false);
        vector<int>inDegree(V,0);
        queue<int>que;
        int vistedVertices=0;
        for(int i=0;i<V;i++)
        {
            vector<int>neigh=adj[i];
            for(auto eachNeigh:neigh)
            {
                inDegree[eachNeigh]++;
            }
            
        }
        
        for(int i=0;i<V;i++)
        {
            if(inDegree[i]==0)
            que.push(i);
        }
        
       while(!que.empty())
       {
        int currVertex=que.front();
        que.pop();
        if(visited[currVertex])
        continue;
        visited[currVertex]=true;
        vistedVertices+=1;
        
        vector<int>neigh=adj[currVertex];
        for(auto eachNeigh:neigh)
        {
            inDegree[eachNeigh]--;
            if(inDegree[eachNeigh]==0)
            que.push(eachNeigh);
            
        }
       }
        if(vistedVertices==V)
        return false;
        
        return true;
        
    }
    
   
};

// { Driver Code Starts.

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