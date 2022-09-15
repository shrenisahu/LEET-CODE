class Solution
{
    public:
        vector<int> findOriginalArray(vector<int> &changed)
        {
            vector<int> ans;
            int n = changed.size();
            if (n % 2 == 1)
                return ans;
            sort(changed.begin(), changed.end());
            unordered_map<int, list < int>> memo;
            set<int> seen;

            for (int i = 0; i < n; i++)
            {
                memo[changed[i]].push_back(i);
            }

            int start = 0;
            int mid = n / 2;

            while (start < mid)
            {

                int doubleValue = changed[start] *2;
                if (seen.find(start) != seen.end())
                {
                    mid++;
                    start++;
                    continue;
                }
                if (doubleValue == changed[start])
                {

                    memo[changed[start]].pop_front();
                    if (memo[changed[start]].size() == 0)
                        memo.erase(changed[start]);
                }

                if (memo.find(doubleValue) != memo.end())
                {
                    ans.push_back(changed[start]);

                    seen.insert(memo[doubleValue].front());
                    memo[doubleValue].pop_front();

                    if (memo[doubleValue].size() == 0)
                        memo.erase(doubleValue);
                }
                else
                {
                    return vector < int> {};
                }
                start++;
            }

            return ans;
        }
};