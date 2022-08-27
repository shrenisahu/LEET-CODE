class Solution
{
    public:
        vector<int> asteroidCollision(vector<int> &asteroids)
        {

            int n = asteroids.size();
           
            stack<int> st;

            for (int i = 0; i < n; i++)
            {
                int currElem=asteroids[i];
                if(currElem >0)
                {
                    st.push(currElem);
                }else
                {
                    while(!st.empty() && st.top() >0 && st.top() <abs(currElem))
                        st.pop();
                    
                    if(st.empty() || st.top() <0 )
                        st.push(currElem);
                    
                    if(st.top()==abs(currElem))
                        st.pop();
                }
            }
            
            int size=st.size();
             vector<int>ans(size);
            int i=0;
            
            while(!st.empty())
            {
               ans[i]=st.top() ;
                i++;
                st.pop();
            }
          
            reverse(ans.begin(),ans.end());
            return ans;
        }
};