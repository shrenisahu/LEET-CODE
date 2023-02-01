class Solution
{
    public:
        string gcdOfStrings(string string1, string string2)
        {

            string str1, str2;
            if (string1.size() > string2.size())
            {
                str1 = string1;
                str2 = string2;
            }
            else
            {
                str1 = string2;
                str2 = string1;
            }
            string ans = "";
            int n = str2.size();	// smaller
            int m = str1.size();	// larger

            for (int i =0; i <n; i++)
            {
                string currStr = str2.substr(0, i + 1);

                bool isBreak = false;
                int len = i + 1;
                if (m % len != 0 || n%len!=0)
                    continue;
                for (int j = 0; j < m; j = j + len)
                {
                    string newstr = str1.substr(j, len);

                    if (currStr != newstr)
                    {
                        isBreak = true;
                        break;
                    }
                }
                 for (int j = 0; j < n; j = j + len)
                {
                    string newstr = str2.substr(j, len);

                    if (currStr != newstr)
                    {
                        isBreak = true;
                        break;
                    }
                }
                
                
                
                
                
                
                
                
                if (!isBreak)
                    ans = currStr;
            }
            return ans;
        }
};