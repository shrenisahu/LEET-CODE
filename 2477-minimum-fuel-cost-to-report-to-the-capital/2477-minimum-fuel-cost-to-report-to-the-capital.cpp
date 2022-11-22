class Solution {
  
      long long dist=0;
long long DFS(int vertex,int parent,vector<vector<int>>&adj, int seats)
    {  
    // cout<<vertex<<" ,";
        
    vector<int>temp=adj[vertex];
   
        
     
          long long people=1;
    for(auto it:temp)
    {
        if(it==parent)
            continue;
        
        int currNum=DFS(it,vertex,adj,seats);
        people+=currNum*1LL;
           
    }
    
    if(vertex!=0)
    {
        int rem=people%seats;
    int quo=people/seats;
    
    if(rem>0)
    {
        dist+=(quo+1)*1LL;
    }
    else 
        dist+=quo*1LL;
    }
    
    
      
         
        return people;
       
        
        
        
        
    }
  
   
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n=roads.size()+1;
        vector<vector<int>>adj(n);
    
        for(auto &it:roads)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
          
        } 
        
        
        
       
        
       int ans= DFS(0,-1,adj,seats);
      
        return dist;
    }
    
    
};