class Solution
{
    public:
        vector<int> findAnagrams(string s, string p)
        {
            int n = p.size();
            int len = s.size();
            vector<int> ans;
            if (n > len)
                return ans;
           
            unordered_map<char, int> smpp;
            unordered_map<char, int> pmpp;
            for (auto &i: p)
                pmpp[i]++;

            int i = 0,j=0;
            while (j < len)
            {

                smpp[s[j]]++;

                if (j - i + 1 == n)
                {
                    if (smpp == pmpp)
                        ans.push_back(i);

                    smpp[s[i]]--;
                    if (smpp[s[i]] == 0)
                        smpp.erase(s[i]);

                    i++;
                }

                j++;
            }
            
            return ans;
        }
};