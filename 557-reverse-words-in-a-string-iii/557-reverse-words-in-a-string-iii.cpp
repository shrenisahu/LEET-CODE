class Solution
{
    public:
        string reverseWords(string s)
        {
            string res = "";
            stringstream strObj(s);
          
            string ans;

            while (getline(strObj,ans,' '))
            {
                reverse(ans.begin(), ans.end());
                res += ans + " ";
            }
            res.pop_back();

            return res;
        }
};