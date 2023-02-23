//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:	
	int mod=1e9+7;
  int spaceOptimization( vector<int>& arr, int n, int sum)
	{
	   
	   vector<int>dp(sum+1,0);
	     
	     dp[0]=1;
	     for(int idx=n-1;idx>=0;idx--)
	     {
	         vector<int>temp(sum+1,0);
	         for(int currSum=0;currSum<=sum;currSum++)
	         {
	             int take=0;
	             if(currSum>=arr[idx])
	             take=dp[currSum-arr[idx]];
	             int notTake=dp[currSum];
	             
	             
	             temp[currSum]=(take+notTake)%mod;
	         }
	         dp=temp;
	     }
	     
	     return dp[sum];
	    
	}
 

   
    int countPartitions(int n, int d, vector<int>& arr) {
       
       int totalSum=0;
       for(auto &i:arr)
       totalSum+=i;
       
   
   if((totalSum-d)%2==1 )
    return 0;
   
   
       
    
       int target=(totalSum+d);
       target/=2;
       
       
   
       int ans=spaceOptimization(arr,n,target);
       return ans;
       
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends