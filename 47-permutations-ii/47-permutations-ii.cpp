class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>> answer;
         vector<int>currConfig;
        set<vector<int>>stt;
        int currIndex=0;
        printPermutations(nums,currIndex,currConfig,stt,answer);
        
        return answer;
    }
    
    void printPermutations(vector<int>& nums, int currIndex ,vector<int>&currConfig, set<vector<int>>&stt, vector<vector<int>> &answer)
    {
        
        if(currIndex>=nums.size())
        {
            
            if(stt.find(currConfig)==stt.end())
            {
               answer.push_back(currConfig);
               stt.insert( currConfig);
            }
             return ;
            
        }
        
        
        for(int i=currIndex;i<nums.size();i++)
        {
            swap(nums[currIndex],nums[i]);
            currConfig.push_back(nums[currIndex]);
            printPermutations(nums,currIndex+1,currConfig,stt,answer);
            
            currConfig.pop_back();
            swap(nums[currIndex],nums[i]);
            
        }
        return ;
    }
};