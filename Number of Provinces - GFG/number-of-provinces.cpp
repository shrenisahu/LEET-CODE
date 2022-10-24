//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
       vector<vector<int>>adjacencyList(V+2);
       
       for(int i=0;i<V;i++)
       {
           for(int j=0;j<V;j++)
           {
               if(adj[i][j]==1 && i!=j)
               {
                   adjacencyList[i+1].push_back(j+1);
                    
               }
           }
       }
       int count=0;
       vector<bool>visited(V+1,false);
       
     for(int i=1;i<=V;i++)
     {
        
         if(visited[i]!=true)
        {
             DFS(i,visited,adjacencyList);
         count++;
        }
     }
       
       
      
       
       return count;
    }
    
    void DFS(int currVertex,vector<bool>&visited, vector<vector<int>>&adjacencyList)
    {
        
        
        if(visited[currVertex]==true)
        return ;
        
        
        visited[currVertex]=true;
        vector<int>neigh=adjacencyList[currVertex];
        for(auto eachNeigh:neigh)
        {
            DFS(eachNeigh,visited,adjacencyList);
        }
        return ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends