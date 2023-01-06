class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &intervals)
        {
          typedef  pair<int,int>pi;
            vector<vector < int>> ans;
            sort(intervals.begin(), intervals.end());
            priority_queue<pi> heap;

            heap.push({ intervals[0][0],
                intervals[0][1] });

            for (int i = 1; i < intervals.size(); i++)
            {
                vector<int> it = intervals[i];
                int x = it[0];
                int y = it[1];
                
                auto currPair=heap.top();
                int x1=currPair.first;
                int y1=currPair.second;
                if(x >y1)
                {
                    heap.push({x,y});
                }
                else
                {
                    heap.pop();
                    int newXCord=min(x,x1);
                    int newYCord=max(y,y1);
                    heap.push({newXCord,newYCord});
                    
                }
            }
            
            
            while(heap.size()>0)
            {
                auto currPair=heap.top();
                heap.pop();
                ans.push_back({currPair.first,currPair.second});
            }
            return ans;
        }
};