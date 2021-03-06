// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<bool>visited(V,false);
       vector<int>answer;
       int currVertex=0;
       BFS(currVertex,visited,adj,answer);
       return answer;
    }
    
    void BFS(int currVertex,  vector<bool>&visited,vector<int> adj[], vector<int>&answer)
    {
        queue<int>que;
        que.push(currVertex);
        
        while(!que.empty())
        {
            int currNode=que.front();
            que.pop();
            
            if(visited[currNode]==true)
            continue;
            
            visited[currNode]=true;
            answer.push_back(currNode);
            
            vector<int>neighbour=adj[currVertex];
            for(auto eachNode:neighbour)
            {
                BFS(eachNode,visited,adj,answer);
            }
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