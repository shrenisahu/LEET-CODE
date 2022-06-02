class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>currCombo;
        int start=1;
      
        generateCombinations(start, n ,k,currCombo,ans);
        return ans;
    }
    
    void generateCombinations(int start,int n, int k,vector<int>&currCombo, vector<vector<int>>&ans)
    {
        if(start>n && k!=0)
            return ;
            
            if(k==0)
            {
              
                ans.push_back(currCombo);
               
                return ;
            }
        
        
      
        for(int i=start ;i<=n;i++)
        {
            currCombo.push_back(i);
            generateCombinations(i+1,n,k-1,currCombo,ans);
            currCombo.pop_back();
        }
        
        return ;
        
    }
};