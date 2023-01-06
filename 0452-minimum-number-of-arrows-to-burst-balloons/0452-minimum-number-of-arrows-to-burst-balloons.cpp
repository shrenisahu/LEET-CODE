class Solution
{
    public:
        int findMinArrowShots(vector<vector < int>> &points)
        {
            typedef pair<int, int> pi;
            sort(points.begin(), points.end());
            priority_queue<pi> heap;
            int lastCount;
            int ans = 1;

            lastCount = points[0][1];

            for (int i = 1; i < points.size(); i++)
            {
                vector<int> it = points[i];
                int x = it[0];
                int y = it[1];

                if (x > lastCount)
                {
                    ans++;
                    lastCount = y;
                }
                else
                {
                    lastCount = min(lastCount, y);
                }
            }

            return ans;
        }
};