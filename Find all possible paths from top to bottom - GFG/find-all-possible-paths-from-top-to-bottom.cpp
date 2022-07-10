// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
         vector<vector<int>> Paths;
        // code here
        int mm=grid.size();
        int nn=grid[0].size();
        vector<int>temp;
        int currRow =0;
        int currCol=0;
        
        findPaths(Paths,mm,nn,currRow,currCol,grid,temp);
        // cout<<Paths.size()<<endl;
        return Paths;
        
    }
    
    void findPaths( vector<vector<int>> &Paths,int m,int n,int currRow,int currCol,vector<vector<int>> &grid,  vector<int>&temp)
    {
        
        if(currRow >= m || currCol >= n || currRow <0 || currCol < 0 || grid[currRow][currCol]==-1)
        return ;
        
        
      
     int currValue=grid[currRow][currCol];
    
     temp.push_back(currValue);
     grid[currRow][currCol]=-1;
     
     if(currRow == m-1 && currCol== n-1)
     Paths.push_back(temp);
    
    findPaths(Paths,m,n,currRow+1,currCol,grid,temp);    
    findPaths(Paths,m,n,currRow,currCol+1,grid,temp);    
    temp.pop_back();
    grid[currRow][currCol]=currValue;
         
         return ;
        
        
        
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends