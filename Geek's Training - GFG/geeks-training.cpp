//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int Memoization(int idx,int j,vector<vector<int>>& points, vector<vector<int>>&dp)
   {
       if(idx>=points.size())
       return  dp[idx][j]=0;
      if(dp[idx][j]!=-1)
      return dp[idx][j];
    
    int ans=0;
    
    for(int k=0;k<=2;k++)
    {
        if(k==j)
        continue;
        
        int temp=points[idx][k]+Memoization(idx+1,k,points,dp);
        ans=max(ans,temp);
        
    }
    
    return dp[idx][j]= ans;
   }
  
  int Tabulation(vector<vector<int>>& arr, int n)
  {
        vector<vector<int>>dp(n+1,vector<int>(4,0));
      
       
      for(int idx=n-1;idx>=0;idx--)
      { 
          for(int task=0;task<=3;task++)
          {
              
              
              for(int last=0;last<=2;last++)
              
              
              {
                  if(last!=task)
                  
                 {
                      int temp=arr[idx][last]+dp[idx+1][last];
                      dp[idx][task]=max(dp[idx][task],temp);
                     
                      
             
                 }
                 
              }
              
          }
      
           
      }
      
     
        return dp[0][3];
        
  }
  
   int spaceOptimization(vector<vector<int>>& arr, int n)
  {
        // vector<vector<int>>dp(n+1,vector<int>(4,0));
      
       vector<int>dp(4,0);
      for(int idx=n-1;idx>=0;idx--)
      { 
           vector<int>temp(4);
          for(int task=0;task<=3;task++)
          {
              
             
              for(int last=0;last<=2;last++)
              
              
              {
                  if(last!=task)
                  
                 {
                      int temp1=arr[idx][last]+dp[last];
                      temp[task]=max(temp[task],temp1);
                     
                      
             
                 }
                 
              }
             
              
          }
       dp=temp;
           
      }
      
     
        return dp[3];
        
  }
  
  
  
  
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
       
    //   int ans=Memoization(0,3,points,dp);
    //   int ans=Tabulation(points,n);
      int ans=spaceOptimization(points,n);
     
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