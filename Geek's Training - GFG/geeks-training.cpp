//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int Solve(int idx,int j,vector<vector<int>>& points, vector<vector<int>>&dp)
   {
       if(idx>=points.size())
       return 0;
      if(dp[idx][j]!=-1)
      return dp[idx][j];
    
    int ans=0;
    
    for(int k=0;k<=2;k++)
    {
        if(k==j)
        continue;
        
        int temp=points[idx][k]+Solve(idx+1,k,points,dp);
        ans=max(ans,temp);
        
    }
    
    return dp[idx][j]= ans;
   }
  
  
  
  
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
           
      int ans=Solve(0,3,points,dp);
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
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends