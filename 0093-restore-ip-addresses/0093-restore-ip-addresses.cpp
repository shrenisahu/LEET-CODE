class Solution
{
    public:
        vector<string> ans;
    bool isValid(string s, int start, int end)
    {
        string h = s.substr(start, end - start + 1);
        int n=h.size();
        if(n==1)
            return true;
        
        if(h[0]=='0')
            return false;
        int num = stoi(h);

        if (num >= 0 && num <= 255)
            return true;

        return false;
    }
    
    bool isLengthValid(string s)
    {
        stringstream X(s);
        string T;
        int dotCount=0;
        
        while(getline(X,T,'.'))
        {
            
            dotCount++;
            
        }
        if(dotCount==4)
            return true;
        
        return false;
    }
    vector<string> restoreIpAddresses(string s)
    {

        int n = s.length();
        if (n > 12)
            return ans;
        
        Traverse(s,0,"");

        return ans;
    }

    void Traverse(string s, int currIdx, string currStr)
    {
        if (currIdx == s.size())
        {
            if(isLengthValid(currStr))
            {
              
            currStr.pop_back();
            ans.push_back(currStr);
            }
            return;
        }

        for (int i = currIdx; i <= currIdx + 2 && i<s.length(); i++)
        {

            string newStr = s.substr(currIdx, i - currIdx + 1);
            if (isValid(s,currIdx,i))
            {
                Traverse(s, i + 1, currStr  + newStr+'.');
            }
        }
        return;
    }
};