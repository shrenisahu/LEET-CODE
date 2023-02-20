//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

bool Tabulate(int n, int sum, vector<int> &arr)
{
     vector<vector<int>>dp(n+1,vector<int>(sum+10));

     for(int i=0;i<=n;i++)
     dp[i][sum]=1;
     int last=arr[n-1];
     dp[n-1][last]=1;

    

    for(int idx=n-1;idx>=0;idx--)
    {
        for(int curr=sum-1;curr>=0;curr--)
        {
            bool notTake=dp[idx+1][curr];
            bool take=false;
            if(curr+arr[idx]<=sum)
            take=dp[idx+1][curr+arr[idx]];
            dp[idx][curr]=take|notTake;
        }
    }

    return dp[0][0];


}

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        int ans=Tabulate(n,sum,arr);
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