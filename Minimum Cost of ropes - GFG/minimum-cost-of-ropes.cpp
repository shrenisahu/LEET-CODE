//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        long long cost=0;
        priority_queue<long long,vector<long long>,greater<long long>>heap ;// minHeap;
        for(long long i=0;i<n;i++)
        {
            heap.push(arr[i]);
        }
       
       while(heap.size() >=2)
       {
           long long first=heap.top();
           heap.pop();
           long long second=heap.top();
           heap.pop();
           long long sum=first+second;
           cost+=sum;
           heap.push(sum);
       }
       
       return cost;
       
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends