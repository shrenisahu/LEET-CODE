//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:



// int idxOfGreaterElem(vector<int>&arr,int target)
// {
    
// }
    int median(vector<vector<int>> &matrix, int R, int C){
        vector<int>arr;
        for(auto i:matrix)
        {
            for(auto it:i)
            {
                arr.push_back(it);
            }
        }
        
        sort(arr.begin(),arr.end());
        int mid=R*C;
        mid=mid/2;
        return arr[mid];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends