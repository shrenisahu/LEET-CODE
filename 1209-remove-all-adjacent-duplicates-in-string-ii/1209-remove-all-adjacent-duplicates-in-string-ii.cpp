class Solution
{
    public:
        string removeDuplicates(string s, int k)
        {

            stack<pair<char, int>> st;

            for (auto i: s)
            {
                if (st.empty() || st.top().first != i)
                {
                    st.push({ i,
                        1 });
                }
                else
                {

                    auto currPair = st.top();
                    char elem = currPair.first;
                    int count = currPair.second;

                    if (count + 1 == k)
                    {
                        while (!st.empty() && st.top().first == i)
                            st.pop();
                    }
                    else
                    {
                        st.push({ i,
                            count + 1 });
                    }
                }
            }

            string res = "";
            while (!st.empty())
            {
                res += st.top().first;
                st.pop();
            }
            cout << res << endl;
            reverse(res.begin(), res.end());
            return res;
        }
};