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
               if( BFS(currVertex,-1,visited,adj))
               return true;
            }
        }
        return false;
    }
    
    bool BFS(int currVertex,int currParent,vector<bool>&visited,vector<int> adj[])
    {
        queue<pair<int,int>>que;
        que.push({currVertex,-1});
        
        while(!que.empty())
        {
            auto currPair=que.front();
            int currNode=currPair.first;
            int Parent=currPair.second;
            que.pop();
            if(visited[currNode])
            continue;
            
            visited[currNode]=true;
            vector<int>neigh=adj[currNode];
            
            for(auto eachNeigh:neigh)
            {
                if(visited[eachNeigh]==false)
                {
                    que.push({eachNeigh,currNode});
                }
                else 
                {
                    if(eachNeigh!=Parent)
                    return true;
                }
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