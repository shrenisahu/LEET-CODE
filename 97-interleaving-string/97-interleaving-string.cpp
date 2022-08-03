class Solution
{
    public:
        bool isInterleave(string s1, string s2, string s3)
        {
            unordered_map<string ,bool>mpp;
            return isSolve(s1, s2, s3, 0, 0, 0,mpp);
        }

    bool isSolve(string s1, string s2, string s3, int p1, int p2, int p3, unordered_map<string ,bool>&mpp)
    {

        if (p1 >= s1.size() && p2 >= s2.size() && p3 >= s3.size())
            return true;
        
        string key=to_string(p1)+'#'+to_string(p2)+'#'+to_string(p3);
        if(mpp.find(key)!=mpp.end())
            return mpp[key];

        bool ans1 = false;
        bool ans2 = false;
        if (p1 < s1.size() && s1[p1] == s3[p3])
        {
            ans1 = isSolve(s1, s2, s3, p1 + 1, p2, p3 + 1,mpp);
        }
        if (p2 < s2.size() && s2[p2] == s3[p3])
        {
            ans2 = isSolve(s1, s2, s3, p1, p2 + 1, p3 + 1,mpp);
        }

        return mpp[key]=ans1 || ans2;
    }
};