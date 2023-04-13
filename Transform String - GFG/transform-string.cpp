//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
       string a=A;
       string b=B;
       sort(a.begin(),a.end());
       sort(b.begin(),b.end());
       
       if(a!=b)
       return -1;
       
       
       int n=A.size();
       int m=A.size();
       
       int i=n-1;
       int j=m-1;
       int count=0;
       while(i>=0 && j>=0)
       {
           
           if(A[i]==B[j])
           {
               i--;
               j--;
           }
           else
           {
               i--;
               count++;
               
           }
           
       }
       
       return count; 
        
        
        
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends