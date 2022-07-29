class Solution
{
    public:
        vector<string> findAndReplacePattern(vector<string> &words, string pattern)
        {
            vector<string>ans;
            unordered_map<char, int> mpp;
            int i = 0;
            string patternMatch = "";
            for (auto j: pattern)
            {
                if (mpp.find(j) == mpp.end())
                {

                    mpp[j] = i;
                    i++;
                    patternMatch += to_string(mpp[j]);
                }
                else
                {
                   
                    patternMatch += to_string(mpp[j]);
                }
            }
            
            
            for(auto eachWord:words)
            {
                 unordered_map<char, int> mpp;
                  int i = 0;
            string patternMatch1 = "";
            for (auto j: eachWord)
            {
                if (mpp.find(j) == mpp.end())
                {

                    mpp[j] = i;
                    i++;
                    patternMatch1 += to_string(mpp[j]);
                }
                else
                {
                   
                    patternMatch1 += to_string(mpp[j]);
                }
            }
                if(patternMatch1==patternMatch)
                {
                    ans.push_back(eachWord);
                }
                
            }
             
          
            return ans;
        }
};