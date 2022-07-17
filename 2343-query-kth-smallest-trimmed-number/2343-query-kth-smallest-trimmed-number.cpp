class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
         int numSize=nums.size();
         
         vector<int>mainAns;
          vector<pair<string,int>>pque;
        for(auto eachVector:queries)
        {
            pque.clear();
            int priorIndex=eachVector[0];
            int trimIndex=eachVector[1];
            int i=0;
             
          
            for(auto eachString:nums)
            {
              
                int eachStringSize=eachString.length();
                
                // string newString=eachString.substr(eachStringSize-trimIndex,trimIndex);
              
              
                pque.push_back({eachString.substr(eachStringSize-trimIndex,trimIndex),i++});
                
              
            }
           sort(pque.begin(),pque.end());
            
            mainAns.push_back(pque[priorIndex-1].second);
           
        }
        
        return mainAns;
        
    }
};