//  TC :O(n log k) which is better than O(nlog n) 

class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            typedef pair<int,int>pq;
            vector<int>ans;
            priority_queue<pq,vector<pq>,greater<pq>>heap;
            unordered_map<int, int> mpp;
            for (auto i: nums)
            {
                mpp[i]++;
            }
            
            for(auto it:mpp)
            {
                heap.push({it.second,it.first});
                if(heap.size() >k)
                {
                    heap.pop();
                }
            }
            
            while(heap.size() >0)
            {
                ans.push_back(heap.top().second);
                heap.pop();
            }
            return ans;
        }
};