class Solution
{
    public:
        int partitionString(string s)
        {

            int n = s.size();
            int i = 0;
            int ans = 0;
            unordered_map<char, int> mpp;
            while (i < n)
            {
                if (mpp.find(s[i]) != mpp.end())
                {

                    ans++;
                    unordered_map<char, int> mpp2;
                    mpp = mpp2;
                }

                mpp[s[i]]++;
                i++;
            }

            return ans + 1;
        }
};