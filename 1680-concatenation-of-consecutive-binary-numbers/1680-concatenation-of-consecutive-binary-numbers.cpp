class Solution {
public:
    int concatenatedBinary(int n) {
        long long add=0;
        int bitWidth=0;
        int mod=1e9+7;
        
        
        for(int i=1;i<=n;i++)
        {
            if(0 == (i&(i-1)))
                bitWidth++;
            
            add=add<<bitWidth;
            
            add|= i;
            
            add%=mod;
            
            
        }
        
        return add;
    }
};