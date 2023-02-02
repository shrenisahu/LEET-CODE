class Solution
{
    public:

        bool isValid(string &a, string &b, unordered_map<char, int> &mpp)
        {

            int m = a.size();
            int n = b.size();
            int i = 0, j = 0;

            while (i < m && j < n)
            {
                char first = a[i];
                char second = b[j];

                if (a[i] == b[j])
                {
                    i++;
                    j++;
                    continue;
                }

                if (mpp[a[i]] > mpp[b[j]])
                    return false;
                else return true;


            }


            if (i < m )
                return false;

            return true;
        }

    bool isAlienSorted(vector<string> &words, string order)
    {
        int m = words.size();

        if (m == 1)
            return true;
        unordered_map<char, int> mpp;

        for (int i = 0; i < order.size(); i++)
        {
            mpp[order[i]] = i;
        }

        for (int i = 0; i < m - 1; i++)
        {
            string a = words[i];
            string b = words[i + 1];

            if (isValid(a, b, mpp) == false)
            {

                return false;
            }
        }

        return true;
    }
};