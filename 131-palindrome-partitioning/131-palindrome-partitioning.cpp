class Solution {
public:
    vector<vector<string>> partition(string s) {
         vector<vector<string>> answer;

        vector<string>currConfig;
        int end=s.size()-1;
        GeneratePalindorme(s , 0, end, currConfig , answer);
        return answer;
       
        
        
        
    }
    
    void GeneratePalindorme(string s,int start,int end, vector<string>&currConfig ,  vector<vector<string>> &answer)
    {
        
        if(start>end){
            answer.push_back(currConfig);
            return ;
        }
        
        for(int i=start;i<=end;i++)
        {
            string leftAns=s.substr(start,i-start+1);
            
            
            if(isPalindrome(leftAns))
            {
                currConfig.push_back(leftAns);
                GeneratePalindorme(s,i+1,end,currConfig,answer);
                currConfig.pop_back();
            }
        }
        
        return ;
    }
    
    
    
    
    bool isPalindrome(string s)
    {
        int start=0;
        int end=s.size()-1;
        
        
        while(start<=end)
        {
            
            if(s[start]!=s[end])
            return false;
            
            start++;
            end--;
        }
        
        return true;
    }
};