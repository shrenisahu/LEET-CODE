class Solution
{
    public:
        int closestMeetingNode(vector<int> &edges, int node1, int node2)
        {
            int n = edges.size();
            vector<int> path = BFS(node1, edges);
            int minAns = INT_MAX;
            int minAnsNode = -1;

            vector<int> path2 = BFS(node2, edges);
            for (int i = 0; i < n; i++)
            {
                
                if (path[i] != -1 && path2[i] != -1)
                    
                {
                   
                    int temp = max(path[i], path2[i]);
                  
                    if(minAns>temp)
                    {
                        
                        minAns=temp;
                        minAnsNode=i;
                    }
            }
        }

    return minAnsNode;
}

vector<int> BFS(int currVeretx, vector<int> &edges)
{
    int n = edges.size();
    queue<pair<int, int>> que;
    que.push({ currVeretx,
        0 });
 
    vector<int> shortestPath(n, -1);

    while (!que.empty())
    {
        auto currPair = que.front();
           que.pop();
        int node = currPair.first;
        int dist = currPair.second;
        if (shortestPath[node] !=-1)
            continue;
      
        shortestPath[node] = dist;

     
        if (edges[node] != -1)
            que.push({ edges[node],
                dist + 1 });
    }

    return shortestPath;
}
};