class Solution
{
    public:
        bool isBipartite(vector<vector < int>> &graph)
        {
            int v = graph.size();

            vector<int> colors(v, -1);

            for (int i = 0; i < v; i++)
            {
                if (colors[i] == -1) {
                    if(!isCycleEven(graph,v,i,0,colors))
                        return false;
                }
            }
            return true;
        }

    bool isCycleEven(vector<vector < int>> &graph, int v, int currVertex, int currColor, vector< int > &colors)
    {
        if (colors[currVertex] != -1)

            return (colors[currVertex] == currColor);

    colors[currVertex] = currColor;
    vector<int> neigh = graph[currVertex];
    for (auto eachNeigh: neigh)
    {
       if (!isCycleEven(graph, v, eachNeigh, 1 - currColor, colors))
        return false;

    }
        return true;

   
}

};