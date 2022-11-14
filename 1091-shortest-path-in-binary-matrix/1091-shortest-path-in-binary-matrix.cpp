class Solution
{

    private:
        bool isValid(int cr, int cc, vector<vector < int>> &grid, int n , vector<vector<bool>> &visited)
        {

            if (cr < 0 || cc < 0 || cr >= n || cc >= n || grid[cr][cc] != 0 || visited[cr][cc]==true)
                return false;

            return true;
        }

    public: vector<vector < int>> dir = {
		{ 1,
            0 },
        { -1,
            0 },
        { 0,
            1 },
        { 0,
            -1 },
        { 1,
            1 },
        { 1,
            -1 },
        { -1,
            1 },
        { -1,
            -1 }
    };
    int shortestPathBinaryMatrix(vector<vector < int>> &grid)
    {
        int n = grid.size();
         vector<vector<bool>> visited(n, vector<bool> (n, false));
        if (grid[0][0] != 0)
            return -1;
        queue<pair<int, int>> que;
        int level = 0;
        que.push({ 0,
            0 });
        visited[0][0]=true;

        while (!que.empty())
        {
            int size1 = que.size();
            level++;
            for (int i = 0; i < size1; i++)
            {

                auto currPair = que.front();
                que.pop();

                int currRow = currPair.first;;
                int currCol = currPair.second;

                if (currRow == n - 1 && currCol == n - 1)
                    return level;
              

                for (auto it: dir)
                {
                    int newRow = currRow + it[0];
                    int newCol = currCol + it[1];

                    if (isValid(newRow, newCol, grid, n,visited))
                    {

                        que.push({ newRow,
                            newCol });
                           visited[newRow][newCol]=true;
                    }
                }
            }
          
        }

        return -1;
    };
};