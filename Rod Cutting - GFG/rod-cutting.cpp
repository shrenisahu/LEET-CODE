//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  
  int Solve(int N,int idx,vector<int>&price,int len, vector<vector<int>>&dp)
  {
      if(N==0)
      return 0;
      
      
      if(idx>=len)
      return 0;
      
      if(dp[N][idx]!=-1)
      return dp[N][idx];
      
      int cut=0;
      if(N-idx-1 >=0)
      cut=price[idx]+Solve(N-(idx+1),idx,price,len,dp);
      int notCut=Solve(N,idx+1,price,len,dp);
      
      return dp[N][idx] =max(cut,notCut);
      
  }
  int Tabulate(int n, vector<int>&nums)
  {
      
        //   vector<vector<int>>dp(n+1,vector<int>(n+1,0));
          
          vector<int>dp(n+1,0);
          
               
              for(int idx=n-1;idx>=0;idx--)
              {
                   vector<int>temp(n+1);
                    for(int N=1;N<=n;N++)
                {
                  int cut=0;
                  if(N-idx-1 >=0)
                  cut=nums[idx]+temp[N-(idx+1)];
                  
                    int notCut=dp[N];
                  
                  temp[N]=max(cut,notCut);
                  
              }
              dp=temp;
          }
          
          return dp[n];
      
  }
  
    int cutRod(int price[], int n) {
        vector<int>nums;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++)
        {
            nums.push_back(price[i]);
            
        }
        
        
       
    //   int ans=Solve(n,0,nums,n,dp);
      int ans=Tabulate(n,nums);
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
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends