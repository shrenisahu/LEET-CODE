class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph=createGraph(numCourses,prerequisites);
        vector<bool>visited(numCourses,false);
        unordered_set<int>stt;
        
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==false)
            {
                if(DFS(i,visited,stt,graph))
                    return false;
            }
        }
        
        return true;
    }
    
    bool DFS(int currVertex,vector<bool>&visited,unordered_set<int>&stt,vector<vector<int>>&graph)
    {
        visited[currVertex]=true;
        stt.insert(currVertex);
        
        vector<int>neigh=graph[currVertex];
        
        for(auto eachNeigh:neigh)
        {
            if(visited[eachNeigh]==false)
            {
                if(DFS(eachNeigh,visited,stt,graph))
                    return true;
            }
            else {
                if(stt.find(eachNeigh)!=stt.end())
                    return true;
            }
            
        }
        
        stt.erase(currVertex);
        return false;
        
        
    }
    
    
    vector<vector<int>>createGraph(int numCourses,vector<vector<int>>& prerequisites)
    {
        vector<vector<int>>graph;
        
        for(int i=0;i<numCourses;i++)
        {
            vector<int>temp1;
            graph.push_back(temp1);
        }
        
        for(auto temp22:prerequisites)
        {
            int a=temp22[0];
            int b=temp22[1];
            vector<int>temp;
            temp=graph[b];
              
            temp.push_back(a);
            graph[b]=temp;
        }
        
        return graph;
     
    }
};