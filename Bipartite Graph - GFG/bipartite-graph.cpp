//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
bool hasOddCycle(int vertex,vector<int>&color,vector<int>adj[],int currColor)
{
    if(color[vertex]!=-1)
    return color[vertex]==currColor;
    color[vertex]=currColor;
    vector<int>neigh=adj[vertex];
    for(auto it:neigh)
    {
        
           if( !hasOddCycle(it,color,adj,1-currColor))
           return false;
        
    }
    return true;
    
}
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	       {
	            if(!hasOddCycle(i,color,adj,1))
	            return false;
	        }
	       }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends