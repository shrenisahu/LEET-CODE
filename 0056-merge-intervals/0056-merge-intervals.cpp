class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &intervals)
        {
            typedef pair<int, int> pi;
            vector<vector < int>> ans;
            sort(intervals.begin(), intervals.end());

            int lastX = intervals[0][0];
            int lastY = intervals[0][1];

            for (int i = 1; i < intervals.size(); i++)
            {
                vector<int> it = intervals[i];
                int x = it[0];
                int y = it[1];

                if (x > lastY)
                {
                    ans.push_back({ lastX,
                        lastY });

                    lastX = x;
                    lastY = y;
                }
                else
                {

                    lastX = min(x, lastX);
                    lastY = max(y, lastY);
                }
            }
            ans.push_back({ lastX,
                lastY });

            return ans;
        }
};