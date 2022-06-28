class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans{-1,-1};
        if(nums.size()<1)
        {
            return ans;
        }
        
        ans[0]=findFirstPosition(nums,target);
        if(ans[0]==-1)
            return ans;
        ans[1]=findLastPosition(nums,target);
        
        return ans;
    }
    
    int findFirstPosition(vector<int>& nums, int target)
    {
        int start=0;
        int end=nums.size()-1;
        int firstPos=-1;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(nums[mid]==target)
            {
                firstPos=mid;
                end=mid-1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        return firstPos;
        
    }
    
   
        int findLastPosition(vector<int>& nums, int target)
    {
        int start=0;
        int end=nums.size()-1;
        int LastPos=-1;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(nums[mid]==target)
            {
                LastPos=mid;
               start=mid+1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        
        return LastPos;
    }
};