class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        
        vector<int>inDegree(n+1,0);
        vector<int>outDegree(n+1,0);
        
        for(auto i:trust)
        {
            int a=i[0];
            int b=i[1];
            
            outDegree[a]++;
            inDegree[b]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(outDegree[i]==0 && inDegree[i]==n-1)
                return i;
        }
        return -1;
    }
    
};