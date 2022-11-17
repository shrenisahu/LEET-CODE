class Solution
{
    public:
        int findTheCity(int n, vector<vector < int>> &edges, int distanceThreshold)
        {

            vector<vector < int>> matrix(n, vector<int> (n, 1e9));

            for (int i = 0; i < n; i++)
            {
                matrix[i][i] = 0;
            }
            for (auto it: edges)
            {
                int src = it[0];
                int dest = it[1];
                int wt = it[2];

                matrix[src][dest] = wt;
                matrix[dest][src] = wt;
            }

            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }

            int ans = INT_MAX;
            int city = 0;
            for (int i = 0; i < n; i++)
            {
                int count = 0;
                for (int j = 0; j < n; j++)
                {

                    if (matrix[i][j] <= distanceThreshold)
                        count++;
                }

                if (count <= ans)
                {
                    ans = count;
                    city = i;
                }
            }

            return city;
        }
};