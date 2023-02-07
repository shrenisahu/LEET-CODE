class Solution
{
    public:
        int totalFruit(vector<int> &fruits)
        {

            unordered_map<int, int> mpp;
            int i = 0;
            int j = 0;
            int n = fruits.size();
            int maxCount = 0;

            while (j < n)
            {

                mpp[fruits[j]]++;

                while (mpp.size() > 2)
                {
                    mpp[fruits[i]]--;

                    if (mpp[fruits[i]] == 0)
                        mpp.erase(fruits[i]);

                    i++;
                }

                maxCount = max(maxCount, j - i + 1);
                j++;
            }

            return maxCount;
        }
};