//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:        
  int minAns=1000000;
  
  
bool Tabulate(int arr[], int sum,int n)
{
     
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        
        for(int idx=0;idx<=n;idx++)
        dp[idx][sum]=1;
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int currSum=sum;currSum>=0;currSum--)
            {
                int take=0;
                if(arr[idx]+currSum<=sum)
                take=dp[idx+1][currSum+arr[idx]];
                
                int notTake=dp[idx+1][currSum];
                
                dp[idx][currSum]=take||notTake;
            }
        }

        
        for(int sum1=0;sum1<=sum/2;sum1++)
	        {
	            if(dp[0][sum1]==1)
	            {
    	            int sum2=sum-sum1;
    	            int diff=abs(sum1-sum2);
    	           // cout<<diff<<" ";
	            minAns=min(minAns,diff);
                }

	        }
	        
	        
	   //   cout<<endl; 
        // cout<<"ans is"<<minAns;
       
    return minAns;
}


	int minDifference(int arr[], int n)  { 
	    
	    int totalSum=0;
	    for(int i=0;i<n;i++)
	    totalSum+=arr[i];
	    
	    
	    
	    vector<vector<int>>dp(n+1,vector<int>(totalSum+1,-1));
	    
	    int ans=Tabulate(arr,totalSum,n);
// cout<<"new"<<ans;
	    
	   
	    
	    
	    return minAns;
	    
	} 
	

};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends