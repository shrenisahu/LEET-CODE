class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
          vector<int> Ans;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            Ans.push_back(sum);
        }
        return Ans;
    }
};