class Solution
{
    public:
        vector<vector < int>> reconstructMatrix(int upper, int lower, vector<int> &colSum)
        {

            int n = colSum.size();

            vector<vector < int>> grid(2, vector<int> (n, 0));

            for (int i = 0; i < n; i++)
            {
                if (colSum[i] == 2)
                {

                    grid[0][i] = 1;
                    grid[1][i] = 1;
                    upper--;
                    lower--;
                    colSum[i] -= 2;
                }

                if (upper < 0 || lower < 0)
                  return   vector<vector < int>> {};
            }

            for (int i = 0; i < n; i++)
            {

                if (colSum[i] == 1 && upper > 0)
                {
                    grid[0][i] = 1;
                    upper--;
                    colSum[i]--;
                }

                if (colSum[i] == 1 && lower > 0)
                {
                    grid[1][i] = 1;
                    lower--;
                    colSum[i]--;
                }

                if (colSum[i] >= 1)
                    return vector<vector < int>> {};
            }

            if (upper > 0 || lower > 0)
               return  vector<vector < int>> {};

            return grid;
        }
};