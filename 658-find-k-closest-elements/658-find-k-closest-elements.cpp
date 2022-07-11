class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int>Elements;
        int start=0;
        int end=n-1;
        int pivot=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(arr[mid]==x)
            {
                pivot=mid;
                break;
            }
            else if(arr[mid]<x)
            {
                pivot=mid;
                start=mid+1;
            }
            else {
                end=mid-1;
            }
            
        }
        // cout<<arr[pivot]<<"  "<<pivot;
        
        int left=(pivot-k <0)?0 : pivot-k;
        int right=(pivot+k >= n)?n-1:pivot+k;
        cout<<left<<" "<<pivot<<"  "<<right<<endl;
        // cout<<" nect"<<endl;
        while(right-left+1 > k)
        {
            int leftDiff=abs(arr[left]-x);
            int rightDiff=abs(arr[right]-x);
            // cout<<leftDiff<<"  "<<rightDiff<<endl;
            if(rightDiff >= leftDiff)
                right--;
          else   left++;
            
        }
        
        for(int i=left;i<=right;i++)
        {
            Elements.push_back(arr[i]);
        }
        return Elements;
    }
};