class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            if(s.length()!=t.length())
                return false;
            unordered_map<char, int> mpp;
            for (int i = 0; i < s.size(); i++)
            {
                char one = s[i];
                char two =t[i];
                mpp[one]++;
                mpp[two]--;
            }
            for (auto count: mpp)
            {

                if (count.second != 0)
                    return false;
            }
            return true;
        }
};