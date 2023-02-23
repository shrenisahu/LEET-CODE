//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
  
    
    int mod = 1e9 + 7;
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if ((totalSum + d) % 2 != 0) return 0; // THIS IS IMPORTANT
        int s = (d + totalSum)/2;
        
        vector<int> dp(s + 1, 0);
        dp[0] = 1;
        
        for(int i = n-1; i >= 0; i--){
            vector<int> tdp(s+1, 0);
            
            for(int isum = 0; isum <= s; isum++){
                int take = 0, nottake = 0;
                
                if(arr[i] <= isum) take = dp[isum - arr[i]];
                nottake = dp[isum];
                
                tdp[isum] = (take + nottake) % mod;
            }
            
            dp = tdp;
        }
        
        return dp[s];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends