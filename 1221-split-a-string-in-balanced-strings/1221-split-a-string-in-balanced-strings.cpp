class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int n=s.size();
        int r=0;
        int l=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')
                l++;
            else r++;
            
            if(r==l)
            {
                ans++;
                r=0;
                l=0;
            }
            
            
            
        }
        
        return ans;
        
    }
};