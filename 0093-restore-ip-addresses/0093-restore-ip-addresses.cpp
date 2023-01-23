class Solution
{
    public:
        
    bool isValid(string s, int start, int end)
    {
        string h = s.substr(start, end - start + 1);
        int n = h.size();
        if (n == 1)
            return true;

        if (h[0] == '0')
            return false;
        int num = stoi(h);

        if (num >= 0 && num <= 255)
            return true;

        return false;
    }

   
    vector<string> restoreIpAddresses(string s)
    {

        int n = s.length();
        vector<string>ans;
        if (n > 12)
            return ans;
        int currDotCount = 0;
        Traverse(s, 0, "", currDotCount,ans);

        return ans;
    }

    void Traverse(string s, int currIdx, string currStr, int &currDotCount,vector<string>&ans)
    {
        if (currIdx == s.size())
        {

            if (currDotCount == 4)
            {

                currStr.pop_back();
                ans.push_back(currStr);
                
            }
            return;
        }

        for (int i = currIdx; i <= currIdx + 2 && i < s.length(); i++)
        {

            string newStr = s.substr(currIdx, i - currIdx + 1);
            if (isValid(s, currIdx, i))
            {
                currDotCount++;
                Traverse(s, i + 1, currStr + newStr + '.', currDotCount ,ans);
                currDotCount--;
            }
        }
        return;
    }
};