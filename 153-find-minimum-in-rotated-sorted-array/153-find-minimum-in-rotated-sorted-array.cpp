class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        
       if(nums[start]<=nums[end])
           return nums[start];
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
         
            if(nums[mid] >nums[mid+1])
            {
               
                return nums[mid+1];
            }
           else  if(nums[mid] <nums[mid-1])
                return nums[mid];
            
          else   if(nums[start]<= nums[mid]){
               cout<<"here";
               start=mid+1;
          }
          
            else end=mid-1;
        }
        
        return -1;
    }
};