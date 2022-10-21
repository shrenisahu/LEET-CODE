class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        int n=nums.size();
        unordered_map<int,int>mpp;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int rough=target-nums[i];
            if(mpp.find(rough)!=mpp.end())
            {
                ans.push_back(mpp[rough]);
                ans.push_back(i);
            }
            else 
            mpp[nums[i]]=i;
        }
        return ans;
        
    }
};