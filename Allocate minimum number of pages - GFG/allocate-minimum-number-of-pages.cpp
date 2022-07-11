// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
       int start=0;
       int end=totalSum(A,N);
      int answer=-1;
      while(start<=end)
      {
          int mid=start+(end-start)/2;
          
          if(isPossible(A,N,M,mid))
          {
              answer=mid;
            //   cout<<answer<<"   ";
              end=mid-1;
          }
          else start=mid+1;
          
          
      }
      return answer;
      
    }
    bool isPossible(int arr[],int BookCount,int totalStudents,int bound)
    {
        int currentStudentCount=1;
        int currSum=0;
        
        for(int i=0;i<BookCount;i++)
        {
            int currBookPage=arr[i];
            if(currBookPage > bound)
            return false;
            
            if(currSum+currBookPage <= bound)
            {
                currSum+=currBookPage;
                
            }
            else
            {
                currentStudentCount++;
                currSum=currBookPage;
                
                if(currentStudentCount>totalStudents)
                return false;
                
            }
            

        }
                    return true;
    }
    
    int totalSum(int arr[],int N)
    {
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        return sum;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends