class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>graph=createGraph(n,connections);
        vector<int>discover(n,-1);
        vector<int>low(n,-1);
        int time=0;
        tarzanAlgo(0,time,-1,graph,discover,low);
        return ans;
    }
    
    void tarzanAlgo(int node,int &time,int currParent,  vector<vector<int>>&graph , vector<int>&discover,vector<int>&low)
    
    {
        discover[node]=time;
        low[node]=time;
        
        
        time++;
        
        for(auto neigh:graph[node])
        {
            if(neigh==currParent)
                continue;
            
            
            if(discover[neigh]!=-1)
            {
                low[node]=min(low[node],discover[neigh]);
                continue;
            }
            
            tarzanAlgo(neigh,time,node,graph,discover,low);
            low[node]=min(low[node],low[neigh]);
            
            if(discover[node] <low[neigh])
                ans.push_back({neigh,node});
            
        }
        
        return ;
        
    }
    
    vector<vector<int>> createGraph(int n, vector<vector<int>>& connections) 
    {
        
        vector<vector<int>>graph(n);
        for(auto &it:connections)
        {
            int u=it[0];
            int v=it[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
            
        }
        
        return graph;
    }
};