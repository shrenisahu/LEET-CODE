class Solution {
public:
    int findCircleNum(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>visited(n,false);
        int answer=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                   dfs(i,n,visited,graph);
                answer+=1;
            }
            
            
        }
        return answer;
    }
    
    
    void dfs(int currVertix,int n,vector<bool>&visited ,vector<vector<int>>& graph)
    {
        if(visited[currVertix]==true)
            return ;
        visited[currVertix]=true;
        
        vector<int>neighbour=graph[currVertix];
        
        for(int i=0;i<neighbour.size();i++)
        {
            if(neighbour[i]==1)
            dfs(i,n,visited,graph);
        }
        return ;
    }
};