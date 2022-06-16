class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        
        for(int currVertex=0;currVertex<n;currVertex++)
        {
            if(color[currVertex]!=-1)
                continue;
            
            if(!hasEvenCycle(currVertex,0,graph,color))
            {
                return false;
            }
        }
        
        return true;
    }
    
    
    bool hasEvenCycle(int currVertex,int currColor,vector<vector<int>>& graph, vector<int>&color )
    {
        if(color[currVertex]!=-1)
        {
            if(color[currVertex]==currColor)
                return true;
             return false;
        }
        
        color[currVertex]=currColor;
        
        vector<int>neigh=graph[currVertex];
         for(auto eachNeigh:neigh)
         {
             if(!hasEvenCycle(eachNeigh,1-currColor,graph,color))
                 return false;
         }
        
        return true;
    }
    
};
