//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
      
      
      vector<int>ans;
      vector<bool>visited(V,false);
      
      queue<int>que;
      
      que.push(0);
      
      while(!que.empty())
      {
          
          int currVertex=que.front();
          que.pop();
          
          if(visited[currVertex]==true)
          continue;
          ans.push_back(currVertex);
          visited[currVertex]=true;
          
          vector<int>neigh=adj[currVertex];
          for(auto eachNeigh:neigh)
          {
              que.push(eachNeigh);
          }
          
      }
      return ans;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends