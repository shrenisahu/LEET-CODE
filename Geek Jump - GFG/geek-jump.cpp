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
    
          int temp1=abs(height[i]-height[i+1] );
          int  oneStep=temp1+Solve(i+1,height,n,dp);
      if(i+2<=n-1)
         {
              int  temp2=abs(height[i]-height[i+2] );
            twoStep=temp2+Solve(i+2,height,n,dp);
         }
       
       
       return  dp[i]= min(oneStep,twoStep);
      
  }
  
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n+1);
       
       dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            int twoStep=10000;
            int oneStep=dp[i+1] + abs(height[i]-height[i+1]) ;
            
            
            if(i<n-2)
            {
                twoStep=abs(height[i]-height[i+2])+dp[i+2];
            }
            
            dp[i]=min(oneStep,twoStep);
           
        }
         return dp[0];
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