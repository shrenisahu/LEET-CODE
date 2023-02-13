//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
  int Solve(int i,vector<int>& height,vector<int>&dp)
  {
      
      
      if(i==0)
      return dp[0]= 0;
      
      if(dp[i]!=-1)
      return dp[i];
       int twoStep=10000;
       int temp1=abs(height[i]-height[i-1] );
       int  oneStep=Solve(i-1,height,dp)+temp1;
      if(i>1)
         {
              int  temp2=abs(height[i]-height[i-2] );
            twoStep=Solve(i-2,height,dp)+temp2;
         }
       
       
       return dp[i]= min(oneStep,twoStep);
      
  }
  
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n+1,-1);
         int ans=Solve(n-1,height,dp);
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