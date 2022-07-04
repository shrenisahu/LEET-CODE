class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph=createGraph(numCourses,prerequisites);
        vector<int>inDegree(numCourses,0);
        vector<bool>visited(numCourses,false);
        vector<int>ans;
        queue<int>que;
        for(int i=0;i<numCourses;i++)
        {
            vector<int>neigh=graph[i];
            
           for(auto eachNeigh:neigh)
           {
               inDegree[eachNeigh]++;
               
           }
        }
        
        for(int i=0;i<numCourses;i++)
        {
            cout<<inDegree[i]<<"   ";
            if(inDegree[i]==0)
            {
                que.push(i);
            }
                
        }
            
        while(!que.empty())
        {
            int currNode=que.front();
            que.pop();
            if(visited[currNode])
                continue;
            visited[currNode]=true;
            ans.push_back(currNode);
            vector<int>neigh=graph[currNode];
            for(auto eachNeigh:neigh)
            {
                inDegree[eachNeigh]--;
                if(inDegree[eachNeigh]==0)
                    que.push(eachNeigh);
            }
        }
            cout<<endl<<ans.size();
            return ( ans.size()==numCourses);
               
            
    }
    
    vector<vector<int>>createGraph(int numCourses, vector<vector<int>>& prerequisites)
        
    {
         vector<vector<int>>graph;
        
        for(int i=0;i<numCourses;i++)
        {
            vector<int>temp;
            graph.push_back(temp);
        }
        
        for(auto eachArray:prerequisites)
        {
            int a=eachArray[0];
            int b =eachArray[1];
            vector<int>temp;
            temp=graph[b];
            temp.push_back(a);
            graph[b]=temp;
        }
        
        return graph;
    }
};