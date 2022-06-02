class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> currConfig;
        vector<vector<int>> answer;
        int currIndex=0;
        generatePermutations(nums,0,currConfig,answer);
        return answer;
        
        
    }
    
    void generatePermutations(vector<int>& nums,int currIndex,vector<int> currConfig,vector<vector<int>> &answer)
    {
        if(currIndex >=nums.size())
        {
            answer.push_back(currConfig);
        }
        
        
        for(int i=currIndex;i<nums.size();i++)
        {
            swap(nums[currIndex],nums[i]);
            currConfig.push_back(nums[currIndex]);
            
            generatePermutations(nums,currIndex+1,currConfig,answer);
            currConfig.pop_back();
            swap(nums[currIndex],nums[i]);
        }
        return ;
        
    }
};