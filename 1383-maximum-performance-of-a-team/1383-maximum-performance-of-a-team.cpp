class Solution
{
    public:
        int mod = 1000000007;
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<int, int>> memo;

        for (int i = 0; i < n; i++)
        {
            memo.push_back({ efficiency[i],
                speed[i] });
        }

        long maxAns = 0;

        long sum = 0;
        sort(rbegin(memo),rend(memo));
        // sort(memo.begin(), memo.end());

        // reverse(memo.begin(), memo.end());

        priority_queue<int, vector < int>, greater < int>> pq;
        
        for (auto &[e,s]:memo)
        {
           
            sum += s;
            pq.emplace(s);
            if (pq.size() >k)
            {
                sum -= pq.top();
                pq.pop();
            }

            maxAns = max(maxAns, sum *e);
        }

        return maxAns % (int)(1e9 + 7);
    }
};