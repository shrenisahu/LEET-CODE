
class Solution
{
    public:
    
    
     int largestRectangleArea(vector<int> &heights)
        {

            int n = heights.size();
            int maxArea = 0;

            stack<int> st;

            for (int i = 0; i <= n; i++)
            {
               
                while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
                {
                    
                    int topVal = heights[st.top()];
                    st.pop();

                    int width ;
                    if (st.empty())
                        width = i;

                    else width = i - st.top() - 1;

                    int area = topVal * width;
                    maxArea = max(maxArea, area);
                }

                st.push(i);
            }

            return maxArea;
        }
    
    
        int maximalRectangle(vector<vector < char>> &matrix)
        {
            int maxArea=0;
            int n = matrix.size();
            int m = matrix[0].size();
            vector<int> histogram(m, 0);

            for (int cr = 0; cr < n; cr++)
            {
                for (int cc = 0; cc < m; cc++)
                {
                    if (matrix[cr][cc] == '1')
                        histogram[cc] += 1;
                    else
                        histogram[cc] = 0;
                    
                    
                    
                }
                int currArea=largestRectangleArea(histogram);
                maxArea=max(maxArea,currArea);
                
               
            }
            
            return maxArea;
        }
};