class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        int track[n+2];
        memset(track,0,sizeof(track));
        vector<int>ans;
        
        for(int i=0;i<bookings.size();i++)
        {
            int a=bookings[i][0];
            int b=bookings[i][1];
            int val=bookings[i][2];
            
            track[a]+=val;
            track[b+1]+=-val;
        }
        
        for(int i=1;i<=n;i++)
        {
           
            track[i]=track[i]+track[i-1];
            ans.push_back(track[i]);
        }
        return ans;
    }
};