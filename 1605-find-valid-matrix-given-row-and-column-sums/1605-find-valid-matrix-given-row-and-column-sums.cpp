class Solution
{
    public:
        vector<vector < int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
        {

            int m = rowSum.size();
            int n = colSum.size();

            vector<vector < int>> grid(m, vector<int> (n, 0));
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int cord = grid[i][j];
                    int a = rowSum[i];
                    int b = colSum[j];

                    int minElem = min(a, b);
                    grid[i][j] = minElem;
                    rowSum[i] -= minElem;
                    colSum[j] -= minElem;
                }
            }

            return grid;
        }
};