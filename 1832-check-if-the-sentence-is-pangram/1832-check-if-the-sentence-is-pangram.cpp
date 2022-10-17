class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        unordered_map<char,int>mpp;
        for(auto &i:sentence)
        {
            
            mpp[i]++;
        }
        if(mpp.size()==26)
            return true;
        
        return false;
    }
};