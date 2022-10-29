class Solution
{
    public:
        int islandPerimeter(vector<vector < int>> &grid)
        {
            int tr = grid.size();
            int tc = grid[0].size();
            int ans = 0;
            set<pair<int, int>> stt;
            for (int i = 0; i < tr; i++)
            {
                for (int j = 0; j < tc; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        DFS(i, j, tr, tc, grid, ans, stt);
                        return ans;
                    }
                }
            }

            return ans;
        }

    void DFS(int cr, int cc, int tr, int tc, vector<vector < int>> &grid, int &ans, set< pair<int, int>> &stt)
    {

        if (cr < 0 || cc < 0 || cr >= tr || cc >= tc || grid[cr][cc] == 0 || stt.find({ cr,
                cc }) != stt.end())
            return;

        stt.insert({ cr,
            cc });
        int count = 0;
        if (cr < tr - 1 && grid[cr + 1][cc] == 1)
        {

            count++;
        }
        if (cr > 0 && grid[cr - 1][cc] == 1)
        {

            count++;
        }
        if (cc < tc - 1 && grid[cr][cc + 1] == 1)
        {

            count++;
        }
        if (cc > 0 && grid[cr][cc - 1] == 1)
        {

            count++;
        }

        DFS(cr + 1, cc, tr, tc, grid, ans, stt);
        DFS(cr - 1, cc, tr, tc, grid, ans, stt);
        DFS(cr, cc + 1, tr, tc, grid, ans, stt);
        DFS(cr, cc - 1, tr, tc, grid, ans, stt);
        ans += (4 - count);
    }
};