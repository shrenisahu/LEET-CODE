class Solution {
public:
    
    int  TotalWays(int curr,int Total,  unordered_map<int ,int>&mpp)
    {
        if(curr==Total)
            return 1;
        if(curr>Total)
            return 0;
        int currKey=curr;
        
        if(mpp.find(currKey)!=mpp.end())
        {
            return mpp[currKey];
        }
            
        
        
        
        
        
        int oneJump= TotalWays(curr+1,Total,mpp);
        int twoJump= TotalWays(curr+2,Total,mpp);
        mpp[currKey]=oneJump+twoJump;
        return oneJump+twoJump;
    }
    
    int climbStairs(int n) {
         unordered_map<int ,int>mpp;
      return   TotalWays(0,n,mpp);
    }
};