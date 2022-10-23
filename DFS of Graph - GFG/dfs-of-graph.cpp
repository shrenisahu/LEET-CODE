//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>visited(V,false);
        
        DFS(0,adj,visited,ans);
        return ans;
    }
    
    
    void DFS(int currVertex,vector<int> adj[],vector<bool>&visited,vector<int>&ans)
    {
        
        if(visited[currVertex]==true)
        return ;
        visited[currVertex]=true;
        ans.push_back(currVertex);
        vector<int>neigh=adj[currVertex];
        
        for(auto eachNeigh:neigh)
        {
            DFS(eachNeigh,adj,visited,ans);
        }
        return ;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends