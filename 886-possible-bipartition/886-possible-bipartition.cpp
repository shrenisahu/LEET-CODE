class Solution
{
    public:
        bool possibleBipartition(int n, vector<vector < int>> &dislikes)
        {

            vector<vector < int>> Graph = createGraph(dislikes, n);
            vector<int> colors(n + 1, -1);
            for (int i = 1; i <= n; i++) {
                if(colors[i]!=-1)
                    continue;
               if( !isCycleEven(i,0,colors,Graph))
                   return false;
                
            }

            return true;
        }

    bool isCycleEven(int currVertex, int currColor, vector<int> &colors, vector<vector< int>> &Graph)
    {
        if(colors[currVertex]!=-1)
        {
            return colors[currVertex]==currColor;
        }
        
        colors[currVertex]=currColor;
        vector<int>neigh=Graph[currVertex];
            for(auto eachNeigh:neigh)
            {
                if(!isCycleEven(eachNeigh,1-currColor,colors,Graph))
                    return false;
            }
        
            return true;
        
    }
    vector<vector < int>> createGraph(vector<vector < int>> &dislikes, int n)
    {
        vector<vector < int>> graph;

        for (int i = 0; i <= n; i++)
        {
            vector<int> temp;
            graph.push_back(temp);
        }

        for (auto eachVector: dislikes)
        {
            int src = eachVector[0];
            int dest = eachVector[1];

            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }
        
       

        return graph;
    }
};