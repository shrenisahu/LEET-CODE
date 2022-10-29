class Solution
{
    public:
        int islandPerimeter(vector<vector < int>> &grid)
        {

            int tr = grid.size();
            int tc  = grid[0].size();

            int res = 0;
            for (int i = 0; i < tr; i++)
            {
                for (int j = 0; j < tc; j++)
                {
                    if (grid[i][j] == 1)
                    {

                        if (i == 0 || grid[i - 1][j] == 0)
                            res += 1;

                        if (i == tr - 1 || grid[i + 1][j] == 0)
                            res += 1;

                        if (j == 0 || grid[i][j - 1] == 0)
                            res += 1;
                        if (j == tc - 1 || grid[i][j + 1] == 0)
                            res += 1;
                    }
                }
            }
            return res;
        }
};