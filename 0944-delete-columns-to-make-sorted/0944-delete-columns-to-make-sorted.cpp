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

                for (int j = 1; j < n; j++)	// 100
                {

                    if (strs[j - 1][i] > strs[j][i])
                    {

                        count++;
                        break;
                    }
                }
            }

            return count;
        }
};