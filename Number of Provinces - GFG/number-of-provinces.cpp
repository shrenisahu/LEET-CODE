//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    
    private:
     int find(vector<int>&parent,int a)
     {
         if(parent[a]==a)
         return a;
         
         else parent[a]=find(parent,parent[a]);
         
         return parent[a];
     }
    void union_(int a ,int b,vector<int>&parent,vector<int>&rank)
    {
        int parA=find(parent,a);
        int parB=find(parent,b);
        
        if(parA==parB)
        return ;
        
        if(rank[parA] >rank[parB])
        {
            parent[parB]=parA;
            
        }
        else if(rank[parA] <rank[parB])
        {
            parent[parA]=parB;
        }
        else
        {
            parent[parA]=parB;
            rank[parB]+=1;
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>parent(V);
        vector<int>rank(V,0);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1)
                {
                    union_(i,j,parent,rank);
                }
            }
        }
        int count=0;
        
        for(int i=0;i<V;i++)
        {
            if(parent[i]==i)
            count++;
        }
        return count;
        
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