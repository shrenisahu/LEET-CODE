class Solution
{
    public:
        vector<vector<vector< int>>> neigh;
    int findTheCity(int n, vector<vector < int>> &edges, int distanceThreshold)
    {

        for (int i = 0; i < n; i++)
        {
            vector<vector < int>> temp;
            neigh.push_back(temp);
        }

        for (auto it: edges)
        {
            int src = it[0];
            int dest = it[1];
            int wt = it[2];
            vector<int> arr;
            arr.push_back(src);
            arr.push_back(wt);
            neigh[dest].push_back(arr);
            neigh[src].push_back({ dest,
                wt });
        }

        int minCount = 1e9;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int currCount = dijkastra(i, n, distanceThreshold);
            if (currCount <= minCount)
            {
                minCount = currCount;
                ans = i;
            }
        }

        return ans;
    }

    int dijkastra(int src, int n, int distanceThreshold)
    {
        vector<int> cost(n, -1);

        priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> que;
        que.push({ 0,
            src });

        while (!que.empty())
        {

            auto currPair = que.top();
            que.pop();

            int vertex = currPair.second;
            int wt = currPair.first;
            if (cost[vertex] != -1)
                continue;
            cost[vertex] = wt;
            vector<vector < int>> tempArr = neigh[vertex];
            for (auto it: tempArr)
            {
                int v = it[0];
                int newWt = it[1];

                que.push({ newWt + wt,
                    v });
            }
        }
        int count = 0;

        for (int i = 0; i < n; i++)
        {

            if (cost[i] <= distanceThreshold && cost[i] > 0)
                count++;
        }

        return count;
    }
};