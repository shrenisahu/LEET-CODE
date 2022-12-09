//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    private:
    
    int findPathByCompression(vector<int>&parents,int a)
    {
        
        if(parents[a]==a)
        return a;
        else 
        {
            parents[a]=findPathByCompression(parents,parents[a]);
        }
        
        return parents[a];
    }
    
     void unionByRank(vector<int>&parents,vector<int>&rank,int a,int b)
    {
        int parA=findPathByCompression(parents,a);
        int parB=findPathByCompression(parents,b);
        
        if(parA==parB)
        return ;
        
        if(rank[parA] <rank[parB])
        {
            parents[parA]=parB;
        }
        else if(rank[parA] >rank[parB])
        {
            parents[parB]=parA;
        }
        else
        {
            parents[parA]=parB;
            rank[parB]+=1;
        }
    }
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int minCost=0;
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
           for(auto j:adj[i])
            {
                int src=i;
                int dest=j[0];
                int wt=j[1];
                edges.push_back({wt,{src,dest}});
            }
        }
        
        vector<int>parents(V);
        vector<int>rank(V,0);
        for(int i=0;i<V;i++)
        {
            parents[i]=i;
        }
        
        sort(edges.begin(),edges.end());
        
        for(auto i:edges)
        {
            int wt=i.first;
            int src=i.second.first;
            int dest=i.second.second;
            
            
            
            int parSrc=findPathByCompression(parents,src);
            int parDest=findPathByCompression(parents,dest);
            
            if(parSrc!=parDest)
            {
                minCost+=wt;
                unionByRank(parents,rank,src,dest);
                
            }
        }
        
        
        
        
        
        
        
        
        
        
        return minCost;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends