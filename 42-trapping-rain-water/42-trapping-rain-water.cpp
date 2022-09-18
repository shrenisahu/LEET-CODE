class Solution {
public:
    int trap(vector<int>& height) {
    int n=height.size();
   
    int leftmax=0,rightmax=0;
    int ans=0;
    int i=0,j=n-1;
    while(i<=j)
    {
        if(height[i]<=height[j])
        {
            if(leftmax<height[i])
                leftmax=height[i];
            else
                ans+=leftmax-height[i];
            i++;
        }
        else
        {
            if(rightmax<height[j])
            {
                rightmax=height[j];
            }
            else
                ans+=rightmax-height[j];
            j--;
        }
    }
    return ans;
}
};