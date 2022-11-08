class Solution
    //the basic intuation is cycle detection iof the node is a part of a cycle then it will not reach the terminal node.nodes which are not part of the cycle are markes as safe
{
    public:
        vector<int> eventualSafeNodes(vector<vector < int>> &graph)
        {

            int V = graph.size();
            vector<int>ans;
            vector<int> safe(V, 0);
            vector<bool> visited(V, false);
            set<int> stt;
            for (int i = 0; i < V; i++)
            {
                if (visited[i] == false)
                    isCycle(i, visited, stt, graph,safe);

            }
            
            for(int i=0;i<V;i++)
            {
                if(safe[i]==1)
                    ans.push_back(i);
            }
            return ans;
        }

    bool isCycle(int currNode, vector<bool> &visited, set<int> &stt, vector< vector< int >> &graph, vector< int > &safe)
    {

        visited[currNode] = true;
        stt.insert(currNode);
        vector<int> neigh = graph[currNode];
        // safe[currNode]=0;
        for (auto eachNode: neigh)
        {
            if (visited[eachNode] == false)
            {
                if (isCycle(eachNode, visited, stt, graph,safe))
                    return true;
            }
            else
            {
                if (stt.find(eachNode) != stt.end())
                    return true;
            }
        }

        stt.erase(currNode);
        safe[currNode]=1;
        return false;
    }
};