class Solution
{
    int maxCycleLength = -1;
    public:
        int longestCycle(vector<int> &edges)
        {
            int n = edges.size();

            vector<bool> visited(n, false);
            vector<int> Graph[n];

           	for(int i=0;i < n;i++)
           	{
           	    if(edges[i]!=-1)
           	    {
           	        Graph[i].push_back(edges[i]);
           	    }
           	}

            for (int currVertex = 0; currVertex < n; currVertex++)
            {

                if (visited[currVertex] == false)
                {
                    unordered_map<int, int> mpp;
                    DFS(currVertex, visited, mpp, 0, Graph);
                }
            }

            return maxCycleLength;
        }

    void DFS(int currVertex, vector<bool> &visited, unordered_map<int, int> &mpp, int pathLength, vector< int > edges[])
    {
        if (visited[currVertex])
        {
            if (mpp.find(currVertex) != mpp.end())
            {
                int temp = pathLength - mpp[currVertex];
                maxCycleLength = max(maxCycleLength, temp);
            }
            return;
        }
        visited[currVertex] = true;
        mpp[currVertex] = pathLength;
        pathLength++;

       vector<int>neigh=edges[currVertex];
        for(auto eachNeigh:neigh)
            DFS(eachNeigh, visited, mpp, pathLength, edges);

        return;
    }
};