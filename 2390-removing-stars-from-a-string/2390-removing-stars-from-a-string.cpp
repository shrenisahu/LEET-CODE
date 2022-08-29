class Solution {
public:
    string removeStars(string s) {
        
        stack<char>st;
        
        for(auto i:s)
        {
            if(i=='*')
            {
                st.pop();
                
            }
            else
            {
                st.push(i);
            }
        }
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
            
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};