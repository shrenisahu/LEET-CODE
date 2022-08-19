class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>count;
         unordered_map<int,int>EndsWith;
        for(auto i:nums)
        {
            count[i]++;
        }
        
        for(auto i:nums)
        {
            
            if(EndsWith[i-1]  >0)
            {
                EndsWith[i-1]--;
                EndsWith[i]++;
                
            }
            else if(count[i+1] >0 && count[i+2] >0)
            {
                EndsWith[i]++;
                count[i+1]--;
                count[i+2]--;
            }
            else 
            {
                return false;
            }
        }
        return true;
    }
};