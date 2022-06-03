class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        
        vector<int>InDegree(n+1);
        vector<int>OutDegree(n+1);
        
        for(int i=0;i<trust.size();i++)
        {
            int trusting=trust[i][0];
            int trusted =trust[i][1];
            
            InDegree[trusted]++;
            OutDegree[trusting]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(InDegree[i]==n-1 && OutDegree[i] ==0)
            {
                
                return i;
             }
        }
        return -1;
        
        
    }
};