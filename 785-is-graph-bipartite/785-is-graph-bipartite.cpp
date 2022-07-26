class Solution
{
    public:
        bool isBipartite(vector<vector < int>> &graph)
        {

            int v = graph.size();
            vector<int> nums(v, -1);

            for (int i = 0; i < v; i++)
            {
                if (nums[i] != -1)
                    continue;

                if (!BFS(i, 0, nums, graph))
                    return false;
            }
            return true;
        }

    bool BFS(int Vertex, int Color, vector<int> &nums, vector<vector< int>> &graph)

    {
        queue<pair<int, int>> que;

        que.push({ Vertex,1});
        nums[Vertex]=1;
        while (!que.empty())
        {
            auto currPair = que.front();
            que.pop();

            int currVertex = currPair.first;
            int currColor = currPair.second;

            if (nums[currVertex] != -1)
            {
                if (nums[currVertex] != currColor)
                    return false;
                  
            }
           else
           {
                nums[currVertex] = currColor;
           }
            vector<int> neigh = graph[currVertex];
          
            for (auto eachNeigh: neigh)
            {
                if(nums[eachNeigh]==-1)
                que.push({ eachNeigh,1 - currColor });
            }
          
        }
          return true;
    }
};