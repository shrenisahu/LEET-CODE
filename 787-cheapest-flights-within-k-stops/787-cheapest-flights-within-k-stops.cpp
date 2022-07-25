class Solution
{
    public:
        int findCheapestPrice(int n, vector<vector < int>> &flights, int src, int dst, int k)
        {

            vector<int> costs(n, INT_MAX);
            vector<int> temp(n, INT_MAX);
            costs[src] = 0;
            temp[src] = 0;

            for (int i = 0; i <=k  ; i++)
            {
                for (auto eachEdge: flights)
                {
                    int src = eachEdge[0];
                    int dest = eachEdge[1];
                    int weight = eachEdge[2];

                    if (temp[src] != INT_MAX)
                        costs[dest] = min(costs[dest], temp[src] + weight);
                }
//                  for (auto i: costs)
//             {
//                 cout << i << "  ";
//             }
//                 cout<<endl<<endl;
//                    for (auto i: temp)
//             {
//                 cout << i << "  ";
//             }
                
                // cout<<endl<<endl;
                temp = costs;
            }
           if(costs[dst]==INT_MAX)
               return -1;
            return costs[dst];
        }
};