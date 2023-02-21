class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int start=0;
        int end=n-1;
        int ans=0;
        if(n==1)
            return nums[0];
        
   for(int i=0;i<n;i=i+2)
   {
       
       
       if(nums[i]==nums[i+1])
           continue;
       
       ans=nums[i];
       break;
       
   }
        return ans;
    
    }
};