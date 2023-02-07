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
            int currCount = 0;

            while (j < n)
            {

                mpp[fruits[j]]++;
                currCount += 1;

                while (mpp.size() > 2)
                {
                    mpp[fruits[i]]--;
                    currCount--;
                    if (mpp[fruits[i]] == 0)
                        mpp.erase(fruits[i]);

                    i++;
                }

                maxCount = max(maxCount, currCount);
                j++;
            }

            return maxCount;
        }
};