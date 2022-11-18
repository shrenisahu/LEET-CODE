class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod=1e9+7;
        typedef pair<long long ,long long> pi;
        vector<vector<pair<long long ,long long>>>adj(n);
        
        for(auto &it:roads)
        {
            long long  src=it[0]*1LL;
            long long dest=it[1]*1LL;
            long long   wt=it[2]*1LL;
            adj[src].push_back({dest,wt});
            adj[dest].push_back({src,wt});
            
        }
        vector<long long>dist(n,LONG_MAX);
        vector<int>path(n,0);
        path[0]=1;
        dist[0]=0;
        priority_queue<pi,vector<pi>,greater<pi>>que;
        que.push({0,0});
        
        while(!que.empty())
        {
            auto currPair=que.top();
            que.pop();
            long long wt=currPair.first;
            long long node=currPair.second;
            
            vector<pair<long long ,long long>>neigh=adj[node];
            for(auto it:neigh)
            {
               int newNode=it.first;
               int newWt=it.second;
                
                if(dist[newNode] > wt+newWt)
                {
                    que.push({dist[node]+newWt,newNode});
                    dist[newNode] =dist[node]+newWt;
                    path[newNode] =path[node]%mod;
                    
                }
                else  if(dist[newNode] == wt+newWt)
                {
                      path[newNode] +=path[node];
                     path[newNode] %=mod;
                }
            }
        }
        
        
        return path[n-1]%mod;
    }
};