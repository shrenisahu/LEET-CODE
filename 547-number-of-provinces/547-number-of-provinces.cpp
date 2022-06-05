class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<bool>visited(n,false);
        int answer=0;
       for(int currCity=0;currCity<n;currCity++)
       {
           if(visited[currCity]==false)
           {
               DFS(currCity,isConnected,visited);
               answer++;
           }
               
       }
        
        return answer;
        
    }
    
    void DFS(int currCity,vector<vector<int>>& isConnected,vector<bool>&visited )
    {
        if(visited[currCity]==true)
            return ;
        
        visited[currCity]=true;
        
        vector<int>neighbour=isConnected[currCity];
        
        for(int i=0;i<neighbour.size();i++)
        {
            if(neighbour[i]==1)
            {
                DFS(i,isConnected,visited);
            }
        }
        
        return ;
    }
    
};