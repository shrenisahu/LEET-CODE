//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
 
  int Solve(int i,vector<int>& height, int n,vector<int>&dp)
  {
      if(i==n-1)
      return  dp[i]=0;
      
      if(dp[i]!=-1)
      return dp[i];
      
      int twoStep=10000;
      int ans=INT_MAX;
       for(int j=1;j<=2;j++)
       {
            if(i+j<=n-1)
         {
            int  temp2=abs(height[i]-height[i+j] );
            twoStep=temp2+Solve(i+j,height,n,dp);
            ans=min(ans,twoStep);
         }
       
       }
       return dp[i]= ans;
      
  }
  
    int minimumEnergy(vector<int>& height, int n) {
        
       vector<int>dp(n+1,-1);
       int ans=Solve(0,height,n,dp);
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends