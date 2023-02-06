//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 int findLastPos(int nums[], int n , int target)
        {
           
            int start = 0;
            int end = n - 1;

            int LastOccurance = -1;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                if (nums[mid] == target)
                {
                    LastOccurance = mid;
                    start = mid + 1;
                }
                else if (nums[mid] > target)
                {
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }

            return LastOccurance;
        }

    

        int findFirstPos(int nums[], int n , int target)
        {
           
            int start = 0;
            int end = n - 1;

            int firstOccurance = -1;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                if (nums[mid] == target)
                {
                    firstOccurance = mid;
                    end = mid - 1;
                }
                else if (nums[mid] > target)
                {
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }

            return firstOccurance;
        }


vector<int> find(int nums[], int n , int x )
{
      
        int start = 0;
        int end = n - 1;
        vector<int> ans(2,0);
        ans[0]=findFirstPos(nums,n,x);
        ans[1]=findLastPos(nums,n,x);
        
        return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends