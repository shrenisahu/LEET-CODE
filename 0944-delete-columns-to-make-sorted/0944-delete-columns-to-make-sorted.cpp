class Solution
{
    public:
        int minDeletionSize(vector<string> &strs)
        {

            int n = strs.size();
            int len = strs[0].size();
            int count = 0;
            for (int i = 0; i < len; i++)	// 1000 *
            {

                int lastWordValue = 96;
                for (int j = 0; j < n; j++)	// 100
                {
                    string currStr = strs[j];
                    char currLetter = currStr[i];
                    int currWordValue = currLetter;
                    if (lastWordValue > currWordValue)
                    {

                        count++;
                        break;
                    }
                    lastWordValue = currWordValue;
                }
            }

            return count;
        }
};