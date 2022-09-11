class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
       
        int maxCount=0;
        int minTime=INT_MAX;
        int maxTime=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int a=intervals[i][0];
            int b=intervals[i][1];
            maxTime=max({maxTime,a,b+1});
            minTime=min({minTime,a,b+1});
           
        }
         int track[maxTime+3];
        memset(track,0,sizeof(track));
        for(int i=0;i<n;i++)
        {
            int a=intervals[i][0];
            int b=intervals[i][1];
            
            track[a]++;
            track[b+1]--;
        }
        
        for(int i=minTime;i<maxTime+2;i++)
        {
            track[i]+=track[i-1];
            maxCount=max(maxCount,track[i]);
        }
        return maxCount;
    }
};