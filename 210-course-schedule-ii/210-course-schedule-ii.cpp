class Solution {
public:
    vector<int>ans;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph=createGraph(numCourses,prerequisites);
         unordered_set<int>stt;
        vector<bool>visited(numCourses,false);
        
        
 for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==false)
            {
                if(DFS(i,visited,stt,graph))
                    return vector<int>{};
            }
        }
        // sort(ans.begin(),ans.end());
        return ans;
      
       
        
       
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
        ans.push_back(currVertex);
        stt.erase(currVertex);
        return false;
        
        
    }
    
      vector<vector<int>> createGraph(int numCourses, vector<vector<int>>& prerequisites)
          {
          vector<vector<int>>graph;
         
          for(int i=0;i<numCourses;i++)
          {
              vector<int>temp;
              graph.push_back(temp);
          }
         
          for(auto eachCourse:prerequisites)
          {
              int a=eachCourse[1];
              int b=eachCourse[0];
              vector<int>temp;
              temp= graph[b];
              temp.push_back(a);
              graph[b]=temp;
          }
          
          return graph;
      }
    
};