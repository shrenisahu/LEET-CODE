class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
        vector<int>ans;
        int first=firstPosition(nums,target);
        if(first==-1)
        return ans;
        
        int last=lastPosition(nums,target);
        
        for(int i=first;i<=last;i++)
        {
            ans.push_back(i);
        }
        return ans;
        
        
        
        
    }
    
    int firstPosition(vector<int>& nums, int x)
    {
        int start=0;
        int end=nums.size()-1;
        int firstPos=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==x)
            {
                firstPos=mid;
                end=mid-1;
            }
            else if(nums[mid]>x)
            {
                end=mid-1;
                
            }
            else {
                start=mid+1;
            }
            
            
        }
        return firstPos;
    }
    
    
     int lastPosition(vector<int>& nums, int x)
    {
        int start=0;
        int end=nums.size()-1;
        int lastPos=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==x)
            {
                lastPos=mid;
                start=mid+1;
            }
            else if(nums[mid]>x)
            {
                end=mid-1;
                
            }
            else {
                start=mid+1;
            }
            
            
        }
        return lastPos;
    }
};