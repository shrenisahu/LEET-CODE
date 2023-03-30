class Solution
{
    public:
        int largestRectangleArea(vector<int> &heights)
        {

            int n = heights.size();
            int maxArea = INT_MIN;

            stack<int> st;

            vector<int> leftMin(n);
             vector<int> rightMin(n);

            for (int i = 0; i < n; i++)
            {
                int currElem = heights[i];
                while (!st.empty() && heights[st.top()] >= currElem)
                {
                    st.pop();
                }
                if (st.empty())
                {
                    leftMin[i] = 0;
                }
                else
                    leftMin[i] = st.top() + 1;

                st.push(i);
            }
            
            
          stack<int> st1;
            
             for (int i = n-1; i >=0; i--)
            {
                int currElem = heights[i];
                while (!st1.empty() && heights[st1.top()] >= currElem)
                {
                    st1.pop();
                }
                if (st1.empty())
                {
                    rightMin[i] = n-1;
                }
                else
                    rightMin[i] = st1.top() -1;

                st1.push(i);
            }
          
             for (int i = 0; i < n; i++)
            {
               
                int width=(rightMin[i]-leftMin[i]+1);
                int area = heights[i]*width;
                 cout<<area<<" ";
                maxArea = max(maxArea, area);
            }


            return maxArea;
        }
};