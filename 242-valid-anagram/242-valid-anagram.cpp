class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpp;
        for(auto eachLetter:s)
        {
            mpp[eachLetter]++;
        }
        for(auto eachLetter:t)
        {
            mpp[eachLetter]--;
            if(mpp[eachLetter]==0)
                mpp.erase(eachLetter);
        }
        if(mpp.size()==0)
            return true;
        return false;
        
    }
};