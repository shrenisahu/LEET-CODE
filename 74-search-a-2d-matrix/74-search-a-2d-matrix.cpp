class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
       
        int start=0;
        int end=(m*n)-1;
      
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int rowCordinate=mid/n;
            int colCordinate=mid%n;
            cout<<mid<<"  "<<rowCordinate<<"  "<<colCordinate<<endl;
            
            int temp=matrix[rowCordinate][colCordinate];
            
            if(temp==target)
                return true;
            
            else if(temp >= target)
                end=mid-1;
            else if(temp<=target)
                start=mid+1;
            
        }
        
        return false;
    }
};