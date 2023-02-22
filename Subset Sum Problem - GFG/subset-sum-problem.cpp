//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

bool Solve(int idx,int sum,int target,vector<int>arr, vector<vector<int>>&dp)
{
    
    
   
    int n=arr.size();
     
    if(idx==arr.size()-1)
    return arr[n-1]==sum;
    if(dp[idx][sum]!=-1)
    return dp[idx][sum];
    int take=0;
    if(sum-arr[idx]>=0)
    take=Solve(idx+1,sum-arr[idx],target,arr,dp);
    
    bool notTake=Solve(idx+1,sum,target,arr,dp);
    
    return dp[idx][sum]= take||notTake;
}


bool Tabulate(vector<int>arr, int sum)
{
     int n=arr.size();
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
    return dp[0][0];
}


    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        int ans=Solve(0,sum,sum,arr,dp);
        // int ans=Tabulate(arr,sum);
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