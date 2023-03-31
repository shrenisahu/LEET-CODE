}
else
leftMin[i] = st.top() + 1;
​
st.push(i);
}
// while(!st.empty())
//     st.pop();
​
//             for (int i = n - 1; i >= 0; i--)
//             {
//                 int currElem = heights[i];
//                 while (st.empty() && heights[st.top()] >= currElem)
//                 {
//                     st.pop();
//                 }
//                 if (st.empty())
//                 {
//                     leftMin[i] = 0;
//                 }
//                 else
//                     leftMin[i] = st.top() - 1;
​
//                 st.push(i);
//             }
for (int i = 0; i < n; i++)
{
cout<<leftMin[i]<<" ";
}
cout<<endl;
for (int i = 0; i < n; i++)
{
cout<<rightMin[i]<<" ";
}
cout<<endl;
for (int i = 0; i < n; i++)
{
int sum = heights[i] *(leftMin[i] - rightMin[i] + 1);
maxArea = max(maxArea, sum);
}
​
return maxArea;
}
};