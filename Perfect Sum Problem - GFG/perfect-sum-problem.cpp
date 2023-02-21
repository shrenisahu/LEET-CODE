//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	int util(int arr[], int n, int sum, int i, vector<vector<int>> &dp){
	    if (i >= n){
	        return sum == 0;
	    }     
	    
	    if (dp[i][sum] != -1) return dp[i][sum];
	    
	    int take = 0, nottake = 0;
	    if (arr[i] <= sum){
	        take = util(arr, n, sum - arr[i], i+1, dp);
	    }
	    nottake = util(arr, n, sum, i+1, dp);
	    
	    return dp[i][sum] = (take + nottake)%mod;
	 }
	 
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        
        return util(arr, n, sum, 0, dp);
	}
	

	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends