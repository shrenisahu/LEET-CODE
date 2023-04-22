class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n=arr.size();
        int start=0;
        int end=n-1;
        int ans=-1;
        while(start<=end)
        {
            
            int mid=start+(end-start)/2;
           
            
            int elem=arr[mid];
            int missCount=elem-(mid+1);
            
            if(missCount>=k)
                end=mid-1;
            
            else
            {
                
                ans=mid;
                start=mid+1;
            }
        }
        // start--;
        // ans=start;
        cout<<ans<<endl;
        
       if(ans==-1)
           return k;
        
        int elem=arr[ans];
        int idx=ans;
        int missCount=k-(elem-(idx+1));
         // cout<<elem<<" , "<<idx<<missCount<<","<<k<<endl;
        return elem+missCount;
        
    }
};