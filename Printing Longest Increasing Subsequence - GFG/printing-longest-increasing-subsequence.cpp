//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        
        vector<int>dp(n,1);
        vector<int>hash(n);
         vector<int> ans;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
        }
        int maxTillNow=1;
        int maxTillNowIdx=0;
        for(int idx=1;idx<n;idx++)
        {
            for(int prev=0;prev<idx;prev++)
            {
                if(arr[idx]>arr[prev])
                {
                    if(dp[idx]<1+dp[prev])
                   {
                        dp[idx]=1+dp[prev];
                        hash[idx]=prev;
                   }
                }
            }
            if(dp[idx]>maxTillNow)
            {
                maxTillNow=dp[idx];
                maxTillNowIdx=idx;
            }
        }
        ans.push_back(arr[maxTillNowIdx]);
       while(maxTillNowIdx!=hash[maxTillNowIdx])
       {
           ans.push_back(arr[hash[maxTillNowIdx]]);
           maxTillNowIdx=hash[maxTillNowIdx];
           
       }
       reverse(ans.begin(),ans.end());
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
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends