// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
         vector<int>answer;
          vector<bool>visited(V+1,false);
         
          int currNode=0;
          DFS(V,0,visited,answer,adj);
          return answer;
        
    }
    
    void DFS(int V,int currNode,  vector<bool>&visited,vector<int>&answer,vector<int> adj[])
    {
        if(visited[currNode]==true)
        return ;
        
        
        visited[currNode]=true;
        answer.push_back(currNode);
        
        vector<int>neighbour=adj[currNode];
        for(auto temp:neighbour)
        {
            DFS(V,temp,visited,answer,adj);
        }
        return ;
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
}  // } Driver Code Ends