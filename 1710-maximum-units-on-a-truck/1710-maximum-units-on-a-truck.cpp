class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int>nums(1001);
        for(auto eachBox:boxTypes)
        {
            int boxes=eachBox[0];
            int units=eachBox[1];
            
            nums[eachBox[1]]+=eachBox[0];
             
        }
        int ans=0;
      for(int i=1000;i>=0;i--)
      {
          int boxValue=nums[i];
          if(truckSize>=boxValue)
          {
              ans=ans+(boxValue*i);
              truckSize-=boxValue;
          }
          else 
          {
              ans=ans+(truckSize*i);
              truckSize=0;
              
          }
      }
        
        return ans;
    }
};