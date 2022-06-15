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
        typedef pair<int, int> pi;
        // Code here
        vector<int>cost(V,-1);
       
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > que;
        que.push({0,S});  // cost ,node
        
        while(!que.empty())
        {
            auto currPair=que.top();
            que.pop();
            int currVertex=currPair.second;
            int currCost=currPair.first;
            
            if(cost[currVertex]!=-1)
            {
                continue;
            }
            cost[currVertex]=currCost;
            
            vector<vector<int>>neigh=adj[currVertex];
            for(auto temp:neigh)
            {
                int nextVertex=temp[0];
                int nextCost=temp[1];
                int newCost=nextCost+currCost;
                que.push({newCost,nextVertex});
            }
        }
       
        return cost;

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