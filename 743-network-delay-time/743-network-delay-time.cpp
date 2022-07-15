class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector<vector<int>>> adj=createGraph(times,n);
        typedef pair<int,int>pi;
        cout<<adj.size();
        vector<int>costs(n+1,-1);
int count=0;
        for(int i=0;i<n;i++)
        {
            cout<<"[";
            vector<vector<int>>j=adj[i+1];
            for(auto e:j)
            {
                cout<<"["<<e[0]<<"  "<<e[1]<<" ]";
            }
            cout<<"]";
        }
    
        int maxAns=-1;
        priority_queue<pi,vector<pi>,greater<pi>>que;
        que.push({0,k});
        
        while(!que.empty())
        {
            cout<<"here"<<endl;
         auto currPair=que.top();
            que.pop();
            int currVertex=currPair.second;
            int currCost=currPair.first;
            if(costs[currVertex]!=-1)
            {
                continue;
            }
            costs[currVertex]=currCost;
            maxAns=max(maxAns,currCost);
            
            vector<vector<int>>neigh=adj[currVertex];
            for(auto eachNeigh:neigh)
            {
                int newVertex=eachNeigh[0];
                int newCost=eachNeigh[1];
                
                que.push({currCost+newCost,newVertex});
            }
        }
       
        
        for(auto l:costs)
        {
            if(l==-1)
                count++;
        }
                
    if(count>1)
        return -1;
        return maxAns;
    }
    
    vector<vector<vector<int>>> createGraph(vector<vector<int>>& times,int n)
    {
       vector<vector<vector<int>>>graph;
       for(int i=0;i<n+1;i++)
       {
           vector<vector<int>>rough;
           graph.push_back(rough);
       }
        
    for(auto eachVector:times)
    {
        int src=eachVector[0];
        int dest=eachVector[1];
        int weight=eachVector[2];
        vector<int>temp;
        temp.push_back(dest);
        temp.push_back(weight);
       
       
        graph[src].push_back(temp);
    }
       return graph; 
    }
};