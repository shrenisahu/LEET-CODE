class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mpp;
            bool ans=false;
        for(auto i:magazine)
        {
            mpp[i]++;
        }
        
        for(auto i:ransomNote)
        {
            if(mpp.find(i)!=mpp.end())
            {
                mpp[i]--;
                if(mpp[i]==0)
                    mpp.erase(i);
                
            }
            else 
            {
                return false;
            }
        }
        return true;
    }
};