class Solution
{
    public:
        int minTime(int n, vector<vector < int>> &edges, vector< bool > &hasApple)
        {
            vector<vector < int>> graph = createGraph(n, edges);

            int ans = DFS(0, -1, graph, hasApple);
            if(ans==0)
                return 0;
            ans-=1;
            return ans * 2;
        }

    int DFS(int currVertex, int currPar, vector<vector < int>> &graph, vector< bool > &hasApple)
    {

        int currScore = 0;

        vector<int> neigh = graph[currVertex];

        for (auto eachNeigh: neigh)
        {
            if (eachNeigh == currPar)
                continue;
            currScore += DFS(eachNeigh, currVertex, graph, hasApple);
            
           
        }
         // cout<<currVertex<<" ->"<<currScore<<endl;

        if (currScore == 0 && hasApple[currVertex] == false)
            return 0;

        if (currScore == 0 && hasApple[currVertex] == true)
            return 1;


        return currScore + 1;
    }

    vector<vector < int>> createGraph(int n, vector<vector < int>> &edges)
    {

        vector<vector < int>> graph;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            graph.push_back(temp);
        }

        for (auto it: edges)
        {
            int a = it[0];
            int b = it[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        return graph;
    }
};