class Solution
{
    public:
        int maxPoints(vector<vector < int>> &points)
        {

            int n = points.size();

            if (n <= 2)
                return n;
            int res = 0;
            for (int i = 0; i < n - 1; i++)
            {
                int duplicates = 1;
                float slope = 0.0;
                unordered_map<float, int> mpp;
                for (int j = i + 1; j < n; j++)
                {
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int dx = x1 - x2;
                    int dy = y1 - y2;

                    if (x1 == x2 && y1 == y2)
                    {
                        duplicates++;
                    }
                    else if (dx == 0)
                    {
                        slope = INT_MAX;
                        mpp[slope]++;
                    }
                    else
                    {
                        slope = (float) dy / (float) dx;
                        mpp[slope]++;
                    }
                }

                int locMax = 0;
                for (auto it: mpp)
                {
                    int freq = it.second;
                    locMax = max(locMax, freq);
                }
                locMax += duplicates;
                res = max(res, locMax);
            }
            return res;
        }
};