class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int>dist(n+1,1e9);
      int maxAns=0;
        dist[k]=0;

        for(int i=0;i<n-1;i++)
        {
            for(auto it:times)
            {
                int src=it[0];
                int dest=it[1];
                int wt=it[2];
                
               
                if(dist[src]+wt <dist[dest])
                {
                    dist[dest]=dist[src]+wt;
                    
                }
            }
        }
       for(int i=1;i<=n;i++)
       {
           int it=dist[i];
          
          
          
               maxAns=max(maxAns,it);
           
       }
        
        if(maxAns==0 || maxAns==1e9)
            return -1;
        return maxAns;
        
    }
};