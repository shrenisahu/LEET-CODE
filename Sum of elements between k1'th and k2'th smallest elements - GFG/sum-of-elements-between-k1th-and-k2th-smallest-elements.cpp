//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
       priority_queue< long long>heap;
       long long sum=0;
       for( long long i=0;i<N;i++)
       {
           heap.push(A[i]);
           if(heap.size()>=K2)
           {
               heap.pop();
               
           }
       }
       
       
       while(heap.size() >K1)
       
       {
           sum+=heap.top();
           heap.pop();
       }
       return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends