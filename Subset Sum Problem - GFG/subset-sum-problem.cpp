//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool Solve(int idx,int target,vector<int>&arr, vector<vector<int>>dp)
{
    
    if(target==0)
    return true;
    
    if(idx<=0)
    return arr[0]==target;
    if(dp[idx][target]!=-1)
    return dp[idx][target];
    
    
    bool notTake=Solve(idx-1,target,arr,dp);
    bool take=false;
    if(target>=arr[idx])
    take=Solve(idx-1,target-arr[idx],arr,dp);
    
    return  dp[idx][target]=notTake||take;
}


bool tabulate(vector<int>arr, int sum)
{
     int n=arr.size();
     vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
     for(int i=0;i<n;i++)
     dp[i][0]=1;
     
     dp[0][arr[0]]=1;
     
     for(int idx=1;idx<n;idx++)
     {
         for(int k=1;k<=sum;k++)
         {
             int notTake=dp[idx-1][k];
             
             int Take=0;
             if(k>=arr[idx])
             Take=dp[idx-1][k-arr[idx]];
             dp[idx][k]=notTake| Take;
             
         }
     }
      
      
      return dp[n-1][sum];
      
}


    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        // bool ans=Solve(n-1,sum,arr,dp);
        bool ans=tabulate(arr,sum);
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends