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
               BFS(currCity,isConnected,visited);
               answer++;
           }
               
       }
        
        return answer;
        
    }
    
    void BFS(int currCity,vector<vector<int>>& isConnected,vector<bool>&visited )
    {
        
        queue<int>que;
        que.push(currCity);
        
        
        while(!que.empty())
        {
            
            int currVertex=que.front();
            que.pop();
            
            if(visited[currVertex]==true)
                continue ;
            visited[currVertex]=true;
            vector<int>neighbour=isConnected[currVertex];
            
            for(int i=0;i<neighbour.size();i++)
            {
                if(neighbour[i]==1)
                {
                    que.push(i);
                }
            }
            
            
        }
        
        return ;
        
        
    }
    
};