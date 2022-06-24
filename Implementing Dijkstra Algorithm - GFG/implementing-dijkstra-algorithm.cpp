// { Driver Code Starts
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
        typedef pair<int,int>pi;
        vector<int>cost(V+1,-1);
        
       
        
        priority_queue<pi,vector<pi>,greater<pi>>que;
         que.push({0,S});
        while(!que.empty())
        {
            auto currPair=que.top();
            que.pop();
            int currCost=currPair.first;
            int currVertex=currPair.second;
            
            if(cost[currVertex]!=-1)
            continue;
            
            
            cost[currVertex]=currCost;
            vector<vector<int>>neighbours=adj[currVertex];
            for(auto currNeigh:neighbours)
            {
               int nextVertex=currNeigh[0];
               int nextCost=currNeigh[1];
               que.push({nextCost+currCost,nextVertex});
            }
            
        }
        
        return cost;
        // Code here
    }
};


// { Driver Code Starts.


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