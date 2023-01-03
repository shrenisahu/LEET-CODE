//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>heap;
        for(int i=0;i<n;i++)
        {
            heap.push(arr[i]);
            
            if(heap.size() >k)
            {
                ans.push_back(heap.top());
                heap.pop();
            }
        }
        
        while(heap.size() >0)
        {
            ans.push_back(heap.top());
            heap.pop();
        }
        return ans;
        // Your code here
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends