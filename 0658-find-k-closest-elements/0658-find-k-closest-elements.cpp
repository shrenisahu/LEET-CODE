class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        typedef pair<int,int>pq;
        vector<int>ans;
        priority_queue<pq>heap;
        for(auto i:arr)
        {
            int diff=abs(i-x);
            heap.push({diff,i});
            
            if(heap.size()>k)
            {
                heap.pop();
                
            }
            
        }
        
        while(heap.size() >0)
        {
            ans.push_back(heap.top().second);
            heap.pop();
            
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};