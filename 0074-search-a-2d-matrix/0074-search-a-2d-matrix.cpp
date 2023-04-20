class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int r=matrix.size();
        int c=matrix[0].size();
        
        int total=r*c;
        
        int start=0;
        int end=total-1;
        
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int cr=mid/c;
            int cc=mid%c;
            int elem=matrix[cr][cc];
            
            if(elem==target)
                return true;
            
            
            if(elem>target)
            {
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return false;
    }
};