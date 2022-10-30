class Solution
{
    public:
        int numEnclaves(vector<vector < int>> &grid)
        {

            int tr = grid.size();
            int tc = grid[0].size();
            int count = 0;
            for (int cc = 0; cc < tc; cc++)
            {
                DFS(0, cc, tr, tc, grid);
            }
            for (int cc = 0; cc < tc; cc++)
            {

                DFS(tr - 1, cc, tr, tc, grid);
            }

            for (int cr = 0; cr < tr; cr++)
            {
                DFS(cr, 0, tr, tc, grid);
            }

            for (int cr = 0; cr < tr; cr++)
            {

                DFS(cr, tc - 1, tr, tc, grid);
            }

            for (int i = 0; i < tr; i++)
            {
                for (int j = 0; j < tc; j++)
                {

                    if (grid[i][j] == 1)
                        count++;
                }
            }
            return count;
        }

    void DFS(int cr, int cc, int tr, int tc, vector<vector < int>> &grid)
    {
        if (cc < 0 || cr < 0 || cr >= tr || cc >= tc || grid[cr][cc] == 0)
            return;

        grid[cr][cc] = 0;
        DFS(cr + 1, cc, tr, tc, grid);
        DFS(cr - 1, cc, tr, tc, grid);
        DFS(cr, cc + 1, tr, tc, grid);
        DFS(cr, cc - 1, tr, tc, grid);

        return;
    }
};