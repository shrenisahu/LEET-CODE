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
    
     
};

/*

It takes a reference to a vector of integers heights as its argument, which represents the heights of the bars in the histogram.

It initializes two stacks st and st1 to store the indices of the heights.

It initializes two vectors leftMin and rightMin, each of size n, where n is the size of the input vector heights. These vectors will store the index of the nearest smaller element to the left and right of each element in the input vector heights, respectively.

It then uses the first stack st to find the index of the nearest smaller element to the left of each element in the input vector heights. For this, it iterates over the input vector heights from left to right. For each element, it compares it with the elements at the top of the stack st until it finds an element that is smaller than it or the stack becomes empty. If the stack becomes empty, it means that there is no smaller element to the left of the current element. Otherwise, the index of the top element of the stack st represents the index of the nearest smaller element to the left of the current element. This index is stored in the leftMin vector for the current element, and the current element's index is pushed onto the stack st.

The second stack st1 is used to find the index of the nearest smaller element to the right of each element in the input vector heights. For this, it iterates over the input vector heights from right to left. For each element, it compares it with the elements at the top of the stack st1 until it finds an element that is smaller than it or the stack becomes empty. If the stack becomes empty, it means that there is no smaller element to the right of the current element. Otherwise, the index of the top element of the stack st1 represents the index of the nearest smaller element to the right of the current element. This index is stored in the rightMin vector for the current element, and the current element's index is pushed onto the stack st1.

Finally, it iterates over the input vector heights to calculate the area of the largest rectangle that can be formed from the histogram. For each element, it calculates the width of the rectangle as the difference between the index of the nearest smaller element to the right and the index of the nearest smaller element to the left plus one. It then calculates the area of the rectangle as the product of the height of the current element and its width. The maximum area found so far is stored in the maxArea variable, which is updated whenever a larger area is found.

The function returns the maximum area that can be formed from the histogram.

*/