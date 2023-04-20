//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:


    bool isPossible(int k,int target ,vector<int> &stalls)
    {
        
        int n=stalls.size();
        int lastIdx=0;
        int cows=1;
        for(int i=1;i<n;i++)
        {
            
            if(abs(stalls[i]-stalls[lastIdx]) >=target)
            {
                lastIdx=i;
                cows++;
            }
             if(cows ==k)
        return true;
        }
        
       
        return false;
        
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        
        int start=0;
        int end=abs(stalls.back()-stalls.front());
        int ans=0;
       
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(isPossible(k,mid,stalls))
            {
                ans=mid;
                start=mid+1;
            }
            else
            end=mid-1;
        }
     
    return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends