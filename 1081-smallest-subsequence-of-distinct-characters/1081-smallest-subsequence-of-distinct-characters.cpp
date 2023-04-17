class Solution
{
    public:
        string smallestSubsequence(string s)
        {

            vector<bool> seen(26, false);
            vector<int> lastIndex(26, 0);
            stack<char> st;
            int n=s.size();

            for (int i = 0; i < n; i++)
            {
                int elem = s[i];
                lastIndex[elem - 'a'] = i;
            }

            for (int i = 0; i < n; i++)
            {

                int elem = s[i];
                if (seen[elem - 'a'])
                    continue;

                while ( !st.empty()&&st.top() >elem && lastIndex[st.top()-'a'] >i ) {
                    
                    seen[st.top()-'a']=false;
                    st.pop();
                }
                st.push(elem);
                seen[elem - 'a'] = true;
            }
            
string ans="";
            while (!st.empty())
            {
                ans += st.top();
                st.pop();
            }

            reverse(ans.begin(), ans.end());
            return ans;
        }
};