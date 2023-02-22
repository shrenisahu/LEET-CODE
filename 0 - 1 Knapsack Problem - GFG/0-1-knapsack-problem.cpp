//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
   
   int Solve(int idx,int currWt,int wt[], int val[], int n, vector<vector<int>>&dp)
   {
       if(currWt==0)
       return 0;
       
       if(idx>=n)
       return 0;
       
       if(dp[idx][currWt]!=-1)
       return dp[idx][currWt];
       
       int take=-10000;
       if(currWt>=wt[idx])
       take=val[idx]+Solve(idx+1,currWt-wt[idx],wt,val,n,dp);
       int notTake=Solve(idx+1,currWt,wt,val,n,dp);
       
       return dp[idx][currWt]= max(take,notTake);
   }
   
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
      int ans=Solve(0,W,wt,val,n,dp);
      return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends