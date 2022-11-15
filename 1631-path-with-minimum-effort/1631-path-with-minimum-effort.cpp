class Solution
{
    private:
        bool isValid(int cr, int cc, int tr, int tc, vector<vector < int>> &heights)
        {
            if (cr < 0 || cc < 0 || cr >= tr || cc >= tc || heights[cr][cc] == -1)
                return false;

            return true;
        }

    public:
        vector<vector < int>> dir = {
		{ 1,
                0 },
            { 0,
                1 },
            { -1,
                0 },
            { 0,
                -1 }
        };
    int minimumEffortPath(vector<vector < int>> &heights)
    {

        int m = heights.size();
        int n = heights[0].size();

        typedef pair<int, pair<int, int>> pi;
        priority_queue<pi, vector < pi>, greater < pi>> que;

        que.push({ 0,{ 0,0 } });

        while (!que.empty())
        {
            int wt = que.top().first;
            auto currPair = que.top().second;
            que.pop();

            int cr = currPair.first;
            int cc = currPair.second;

            if (heights[cr][cc] == -1)
                continue;
            if (cr == m - 1 && cc == n - 1)
                return wt;

            for (int i = 0; i <= 3; i++)
            {
                int nr = cr + dir[i][0];
                int nc = cc + dir[i][1];
                if (isValid(nr, nc, m, n, heights))
                {
                    int cdiff = abs(heights[cr][cc] - heights[nr][nc]);
                    int diff = max(cdiff, wt);
                    que.push({ diff,{nr,nc} });
                }
            }

            heights[cr][cc] = -1;
        }

        return 0;
    }
};