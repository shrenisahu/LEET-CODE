class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxElem=*max_element(nums.begin(),nums.end());
        cout<<maxElem;
        int subarrayCount=0,ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i]==maxElem)
            {
                subarrayCount++;
                
            }
            else
            {
                subarrayCount=0;
            }
            ans=max(ans,subarrayCount);
        }
        return ans;
        
    }
};