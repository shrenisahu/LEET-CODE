class Solution
{
    public:
        long long distinctNames(vector<string> &ideas)
        {

            unordered_set<string> suffixes[26];
            long long ans = 0;
            for (auto &i: ideas)
            {
                char start = i[0];
                int temp = start - 97;
                int m = i.size();
                string halfWord = i.substr(1, m - 1);

                suffixes[temp].insert(halfWord);
            }
            for (int i = 0; i < 25; i++)

            {
                 
                for (int j = i + 1; j < 26; j++)
                {
                    int count = 0;

                    for (auto &eachSetWord: suffixes[i])
                    {
                        if (suffixes[j].count(eachSetWord))
                        {
                           
                            count++;
                        }
                    }

                    int temp = (suffixes[i].size() - count) *(suffixes[j].size() - count) *2;
                    ans += temp;
                }
            }

            return ans;
        }
};