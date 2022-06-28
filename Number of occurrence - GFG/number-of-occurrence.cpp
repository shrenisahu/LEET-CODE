// { Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int first=firstPosition(arr,n,x);
	    if(first==-1)
	    return 0;
	    int last=LastPosition(arr,n,x);
	    
	    int ans=last-first+1;
	    return ans;
	}
	
	int firstPosition(int arr[], int n, int x)
	{
	    int start=0;
	    int end=n-1;
	    int firstPos=-1;
	    while(start<=end)
	    {
	        int mid=start+(end-start)/2;
	        
	        if(arr[mid]==x)
	        {
	           firstPos=mid;
	           end=mid-1;
	           
	        }
	        else if(arr[mid]>x)
	        {
	            end=mid-1;
	            
	        }
	        else {
	            start=mid+1;
	        }
	        
	    }
	    return firstPos;
	}
	int LastPosition(int arr[], int n, int x)
	{
	    int start=0;
	    int end=n-1;
	  
	    int lastPos=-1;
	    
	    while(start<=end)
	    {
	          int mid=start+(end-start)/2;
	          if(arr[mid]==x)
	          {
	              lastPos=mid;
	              start=mid+1;
	          }
	          
	          else if(arr[mid]>x)
	          {
	              end=mid-1;
	          }
	          else {
	              start=mid+1;
	          }
	        
	    }
	    return lastPos;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends