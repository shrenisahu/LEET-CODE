//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<int> pos
        { -1, 0, 1 };
        
        
        
      

    int Solve(int r, int c1, int c2, int n, vector<vector < int>> &grid, vector<vector<vector<int>>>&dp)
    {
        // if (c1 < 0 || c2 < 0 || c1 >= n || c2 >= n)
        //     return -100000;
if(r==grid.size())
return 0;
        // if (r == grid.size()-1)
        // {

        //     if (c1 == c2)
        //         return grid[r][c1];

        //     else
        //         return grid[r][c1] + grid[r][c2];
        // }
        if(dp[r][c1][c2]!=-1)
        return dp[r][c1][c2];

        int maxi = -10000;
        for (auto i: pos)
        {

            for (auto j: pos)
            {
                if(c1+i >=0 && c1+i<n && c2+j >=0 && c2+j<n)


               {
                    if (c1 == c2)
                {
                    int temp = grid[r][c1] + Solve(r + 1, c1 + i, c2 + j, n,grid,dp);
                    maxi = max(maxi, temp);
                }
                else
                {
                    int temp = grid[r][c1] + grid[r][c2] + Solve(r + 1, c1 + i, c2 + j, n,grid,dp);
                    maxi = max(maxi, temp);
                }
               }
            }
        }

        return dp[r][c1][c2]= maxi;
    }
      int Tabulate(int n, int m, vector<vector<int>>& grid)
        {
             vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,0)));
             
            
             
             
             for(int r=n-1;r>=0;r--)
             {
                 for(int c1=m-1;c1>=0;c1--)
                 {
                       for(int c2=m-1;c2>=0;c2--)
                       {
                             int maxi = -10000;
        for (auto i: pos)
        {

            for (auto j: pos)
            {
                if(c1+i >=0 && c1+i<m && c2+j >=0 && c2+j<m)


               {
                    if (c1 == c2)
                {
                    int temp = grid[r][c1] + dp[r + 1][ c1 + i][c2 + j];
                    maxi = max(maxi, temp);
                }
                else
                {
                    int temp = grid[r][c1] + grid[r][c2] + dp[r + 1][ c1 + i][c2 + j];
                    maxi = max(maxi, temp);
                }
               }
            }
        }

        return dp[r][c1][c2]= maxi;
                       }
                 }
             }
               return dp[0][0][n-1];
        }
        
        
        int Tabulation(vector<vector<int>>& grid)
        {
            int tr=grid.size();
            int tc=grid[0].size();
             vector<vector<vector<int>>>dp(tr+1,vector<vector<int>>(tc+1,vector<int>(tc+1,0)));
            
            
           
            
            for(int r=tr-1;r>=0;r--)
            {
                for(int c1=tc-1;c1>=0;c1--)
                {
                    for(int c2=tc-1;c2>=0;c2--)
                    {  
                        int maxi = -10000;
        for (auto i: pos)
        {

            for (auto j: pos)
            {
                if(c1+i >=0 && c1+i<tc && c2+j >=0 && c2+j<tc)


               {
                    if (c1 == c2)
                {
                    int temp = grid[r][c1] + dp[r+1][c1+i][c2+j];
                    maxi = max(maxi, temp);
                }
                else
                {
                    int temp = grid[r][c1] + grid[r][c2] + dp[r+1][c1+i][c2+j];
                    maxi = max(maxi, temp);
                }
               }
            }
        }
                       
       

       dp[r][c1][c2]=maxi;
                        
                    }
                }
            }
            
            
            
            return dp[0][0][tc-1];
        }
        
    int solve(int n, int m, vector<vector<int>>& grid) {
        
    //   vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
    //   int ans=Solve(0,0,m-1,m,grid,dp);
     int ans=Tabulation(grid);
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends