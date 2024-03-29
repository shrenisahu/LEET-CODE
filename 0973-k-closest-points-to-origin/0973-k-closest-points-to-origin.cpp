class Solution
{
    public:
        vector<vector < int>> kClosest(vector<vector < int>> &points, int k)
        {
            typedef pair<int, pair<int, int>> pi;
            priority_queue<pi> heap;	// maxHeap
            vector<vector < int>> ans;
            for (auto eachPair: points)
            {
                int x = eachPair[0];
                int y = eachPair[1];
                int dist = ((x *x) + (y *y));
               
                heap.push({ dist,
                    {
                        x,
                        y
                    } });

                if (heap.size() > k)
                    heap.pop();
            }
            while (heap.size() > 0)
            {
                auto currPair = heap.top();
                int x = currPair.second.first;
                int y = currPair.second.second;
                ans.push_back({ x,
                    y });

                heap.pop();
            }

            return ans;
        }
};