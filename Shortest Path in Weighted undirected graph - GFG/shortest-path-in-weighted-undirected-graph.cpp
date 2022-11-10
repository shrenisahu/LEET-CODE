//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    typedef pair<int,int>pi;
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>>graph(n+1);
        
        for(auto it:edges)
        {
            int src=it[0];
            int dest=it[1];
            int wt=it[2];
            
            graph[src].push_back({dest,wt});
             graph[dest].push_back({src,wt});
        }
        
        
        
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1,-1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
        
        priority_queue<pi,vector<pi>,greater<pi>>que;
        que.push({0,1});
       
        dist[1]=0;
        
        
        while(!que.empty())
        {
           
            auto currPair=que.top();
            que.pop();
            int node=currPair.second;
            int newDist=currPair.first;
            
           
            for(auto it:graph[node])
            {
                
                int ver=it.first;
                int newWt=it.second;
               
                if(dist[ver] >newWt+newDist)
                {
                   
                    dist[ver] =newWt+newDist;
                    que.push({newWt+newDist,ver});
                    parent[ver]=node;
                }
                
            }
            
            
        }
        if(dist[n]==1e9)
        return {-1};
        vector<int>ans;
      int node=n;
      ans.push_back(node);
      while(node !=parent[node])
      {
          ans.push_back(parent[node]);
          node=parent[node];
      }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends