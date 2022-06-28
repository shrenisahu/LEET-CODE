class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>nums=arr;
       sort(nums.begin(),nums.end());
        unordered_map<int,int>mpp;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
           if(mpp.find(nums[i])==mpp.end())
           {
               mpp[nums[i]]=count;
               count++;
           }
        }
       
        
      for(int i=0;i<arr.size();i++)
      {
          int x=arr[i];
          int temp=mpp[x];
          arr[i]=temp+1;
      }
return arr;
    }
};