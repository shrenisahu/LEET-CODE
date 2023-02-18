class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int a= abs(nums[0]-nums[n-3]); // we will change tht 2 biggest nums with some with that is already present so now minbecomes zero but we need to minimize the minimun,so last two nums are changes so now the masDiff will be nums[0]-nums[n-3]
        int b=abs(nums[2]-nums[n-1]); // now we will change the start 2 smaller nums to some existing value
        int c=abs(nums[1]-nums[n-2]); // change the larget and smallest
        
        return min({a,b,c});
        
    }
};