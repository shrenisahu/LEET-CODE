class Solution
{
    public:
        int findMinArrowShots(vector<vector < int>> &points)
        {
            typedef pair<int, int> pi;
            sort(points.begin(), points.end());
            priority_queue<pi> heap;
            heap.push({ points[0][0],
                points[0][1] });

            for (int i = 1; i < points.size(); i++)
            {
                vector<int> it = points[i];
                int x = it[0];
                int y = it[1];

                auto currPair = heap.top();
                int x1 = currPair.first;
                int y1 = currPair.second;
                if (x > y1)
                    heap.push({ x,
                        y });
                else
                {
                    heap.pop();
                    int newCord=min(y,y1);
                    heap.push({ x,
                        newCord});
                }
            }

            return heap.size();
        }
};