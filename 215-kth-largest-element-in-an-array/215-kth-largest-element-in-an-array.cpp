class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>que;
        
        for(int i=0;i<nums.size();i++)
        {
            que.push(nums[i]);
            
            if(que.size()>k)
            {
                que.pop();
            }
        }
        return que.top();
    }
};