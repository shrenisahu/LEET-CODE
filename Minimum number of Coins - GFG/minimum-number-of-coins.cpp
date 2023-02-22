//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
  
// Solve(int N,vector<int>&coins)
// {
    
    
//     for(int i=coins.size();i>=0;i--)
//     {
        
//     }
    
// }

    vector<int> minPartition(int N)
    {
        vector<int>coins{1,2,5,10,20,50,100,200,500,2000};
        vector<int>ans;
        for(int i=coins.size()-1;i>=0;i--)
        {
            int currCoin=coins[i];
            while(N>=currCoin)
            {
                int quo=N/currCoin;
                N=N%currCoin;
                if(quo>0)
                {
                    for(int j=0;j<quo;j++)
                    ans.push_back(currCoin);
                }
                
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends