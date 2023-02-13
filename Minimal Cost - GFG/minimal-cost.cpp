//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int Solve(int i,vector<int>& height, int n,vector<int>&dp,int k)
  {
      if(i==n-1)
      return  dp[i]=0;
      
      if(dp[i]!=-1)
      return dp[i];
      
      int twoStep=10000;
      int ans=INT_MAX;
       for(int j=1;j<=k;j++)
       {
            if(i+j<=n-1)
         {
            int  temp2=abs(height[i]-height[i+j] );
            twoStep=temp2+Solve(i+j,height,n,dp,k);
            ans=min(ans,twoStep);
         }
       
       }
       return dp[i]= ans;
      
  }
  int Tabulation(vector<int>& height, int n,int k)
  {
       vector<int>dp(n+1);
       dp[n-1]=0;
       for(int i=n-2;i>=0;i--)
       {
           int ans=10000;
           for(int j=1;j<=k;j++)
           {
               int oneStep=10000;
               if(i+j<n)
           
         {
                oneStep=abs(height[i]-height[i+j] )+dp[i+j];
           
         }
         ans=min(ans,oneStep);
           
           }
           dp[i]=ans;
       }
       
       return dp[0];
  }
  
  
  
  
    int minimizeCost(vector<int>& height, int n, int k) {
     vector<int>dp(n+1,-1);
    //  int ans=Tabulation(height,n,k);
     int ans=Solve(0,height,n,dp,k);
     return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends