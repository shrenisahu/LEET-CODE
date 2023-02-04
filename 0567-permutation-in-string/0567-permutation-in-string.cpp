class Solution
{
    public:
        bool checkInclusion(string s1, string s2)
        {
           

           if(s1.size()>s2.size())
               return false;

            unordered_map<char, int> mpp2;
            int n = s1.size();

            for (auto &i: s1)
                mpp2[i]++;

            for (int i = 0; i < s2.size() - n + 1; i++)
            {
                int j = i;
                unordered_map<char, int> mpp = mpp2;

                int count = 0;
                while (mpp.find(s2[j]) != mpp.end())
                {

                    mpp[s2[j]]--;
                    count++;
                    j++;
                    if (mpp[s2[j]] == 0)
                        mpp.erase(s2[j]);
                }

                if (count == s1.size())
                    return true;
            }

            return false;
        }
};