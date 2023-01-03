class Compare {
public:
   bool operator()( pair<int, int> a, pair<int, int> b)
        {
            if (a.first == b.first)
            {
                
                return b.second > a.second;
            }
            return a.first >b.first;
        }
};
class Solution
{
    public:
      
    vector<int> frequencySort(vector<int> &nums)
    {
        
        vector<int> ans;
        unordered_map<int, int> mpp;
        priority_queue<pair<int, int>, vector< pair<int, int>>, Compare> pq;
        for (auto i: nums)
        {
            mpp[i]++;
        }
        for (auto it: mpp)
        {
            int elem = it.first;
            int freq = it.second;
            pq.push({ freq,
                elem });
        }

        while (pq.size() > 0)
        {
            int freq = pq.top().first;
            int elem = pq.top().second;

            for (int i = 0; i < freq; i++)
            {
                ans.push_back(elem);
            }
            pq.pop();
        }
        return ans;
    }
};