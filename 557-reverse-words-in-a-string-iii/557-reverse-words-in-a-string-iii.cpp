class Solution
{
    public:
        string reverseWords(string s)
        {
            string res="";
            stringstream strObj;
            strObj << s;

            string ans;

            while (strObj >> ans)
            {
               reverse(ans.begin(),ans.end());
                   res+=ans+" ";
            }
            res.pop_back();

            return res;
        }
};