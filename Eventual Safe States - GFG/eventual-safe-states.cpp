//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        set<int>stt;
        vector<int>safe(V,0);
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
            hasCycle(i,visited,stt,safe,adj);
            }
        }
        
        for(int i=0;i<V;i++)
        {
            if(safe[i]==1)
            ans.push_back(i);
        }
        return ans;
    }
    
    
    
    bool hasCycle(int node,vector<bool>&visited,set<int>&stt,vector<int>&safe, vector<int> adj[])
    {
        
        
        visited[node]=true;
        stt.insert(node);
        for(auto i:adj[node])
        {
            
            
            if(visited[i]==false)
            {
                if(hasCycle(i,visited,stt,safe,adj))
                return true;
            }
            else
            {
                if(stt.find(i)!=stt.end())
                return true;
            }
        }
        safe[node]=1;
        stt.erase(node);
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends