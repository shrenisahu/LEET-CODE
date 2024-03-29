class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mpp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        // mpp['I']=1;
        // mpp['V']=5;
        // mpp['X']=10;
        // mpp['L']=50;
        // mpp['C']=100;
        // mpp['D']=500;
        // mpp['M']=1000;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(mpp[s[i]] <mpp[s[i+1]])
            {
                res=res-mpp[s[i]];
            }
            else
            {
                res+=mpp[s[i]];
            }
        }
        return res;
    }
};