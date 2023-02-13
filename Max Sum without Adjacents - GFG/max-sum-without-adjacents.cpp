//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	
	int Solve(int i,int *arr,int n,  vector<int>&dp)
	{
	    if(i>=n)
	    {
	        return  0;
	    }
	    
	  if(dp[i]!=-1)
	  return dp[i];
	    int take=arr[i]+Solve(i+2,arr,n,dp);

	    int notTake=Solve(i+1,arr,n,dp);
	  return dp[i]= max(take,notTake);
	    
	}
	int findMaxSum(int *arr, int n) {
	    vector<int>dp(n+1,-1);
	    int ans=Solve(0,arr,n,dp);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends