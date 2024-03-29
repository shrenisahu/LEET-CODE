//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;
        vector<int>visited(V,-1);
        
        que.push({0,S});
        while(!que.empty())
        {
            auto currPair=que.top();
            que.pop();
            int node=currPair.second;
            int currCost=currPair.first;
            
            if(visited[node]!=-1)
            continue;
        //   cout<<currCost<<" ,";
            visited[node]=currCost;
            
            vector<vector<int>>neigh=adj[node];
            for(auto eachNeigh:neigh)
            {
                int newNode=eachNeigh[0];
                int newCost=eachNeigh[1];
                
                que.push({newCost+currCost,newNode});
            }
        }
      
      
        return visited;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends