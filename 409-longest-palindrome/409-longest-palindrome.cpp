class Solution
{
    public:
        int longestPalindrome(string s)
        {
            int length = 0;
            bool oddFlag = false;
            unordered_map<char, int> mpp;
            for (auto i: s)
            {
                mpp[i]++;
            }

            for (auto temp: mpp)
            {

                int currLen = temp.second;

                if (currLen % 2 != 0 && oddFlag == false)
                {
                    oddFlag = true;
                    length += 1;
                }

                int rem = currLen / 2;

               
                length += rem * 2;
            }

            return length;
        }
};