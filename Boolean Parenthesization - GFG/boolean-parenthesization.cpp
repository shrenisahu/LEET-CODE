//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int mod=1003;

//   int Solve(int i,int j,int isTrue,string &S,  vector<vector<vector<int>>>&dp)
//   {
       
//       //Tc:O(N* N *N)*2;
//       if(i>j)
//       return 0;
       
       
//       if(i==j)
//       {
//           if(isTrue==1) // means we want the exp to yield true
//           return S[i]=='T';// if the single elem is Treturn 1 else retru 0
//           else  // means we want the exp to yield false
//           return S[i]=='F';  // if the single elem is F return 1 else retru 0
//       }
//       if(dp[i][j][isTrue]!=-1)
//       return dp[i][j][isTrue];
//       int waysTrue=0;
//       int waysFalse=0
       
//       for(int k=i+1;k<=j;k=k+2) 
//       {
//           int leftTrue=Solve(i,k-1,1,S,dp);
//           int leftFalse=Solve(i,k-1,0,S,dp);
//           int rightTrue=Solve(k+1,j,1,S,dp);
//           int rightFalse=Solve(k+1,j,0,S,dp);
           
           
//           if(S[k]=='&')
//           {
//               if(isTrue==1) // isTrue ==1 means,we want the expression to yield true
//               {
//                   ways+=(leftTrue*rightTrue);
//               }
//                 // no of ways the two expression can be evaluated to true is oparand is "&"
                   
               
//               else  
//               {
//                   ways+=(leftTrue*rightFalse)+(rightTrue*leftFalse)+(leftFalse*rightFalse);
//                     // no of ways the two expression can be evaluated to false is oparand is "&"
                   
//               }
               
//           }
//           else if(S[k]=='|')
//           {
//               if(isTrue==1) // 
//               {
//                   ways+=(leftTrue*rightFalse)+(rightTrue*leftFalse)+(leftTrue*rightTrue);
//                   // no of ways the two expression can be evaluated to true is oparand is "|"
                   
//               }
//               else
//               {
//                   ways+=(leftFalse*rightFalse);
//                     // no of ways the two expression can be evaluated to false is oparand is "|"
                   
//               }
               
               
               
//           }
//           else if(S[k]=='^')
//           { 
//               if(isTrue==1) // 
//               {
//                   ways+=(leftTrue*rightFalse)+(rightTrue*leftFalse);
                  
                   
//               }
//               else
//               {
//                   ways+=(leftTrue*rightTrue)+(leftFalse*rightFalse);
                   
                   
//               }
               
//           }
           
//           ways=ways%mod;
           
           
//       }
       
       
//       return dp[i][j][isTrue]= ways;
//   }
   
   
   int Tabulate(int N, string S)
   {
       
    vector<vector<vector<int>>>dp(N+2,vector<vector<int>>(N+2,vector<int>(2,0)));
    for(int i=0;i<=N;i++)
    {
      
            
            
                if(S[i]=='T')
                {
                    dp[i][i][1]=1;
                }
                else
                {
                    dp[i][i][0]=1;
                    
                }
            
    }
    
    
  
    
    for(int i=N-1;i>=0;i--)
    {
        for(int j=0;j<=N-1;j++)
        {
            if(i>j )
            continue;
            
            
            int waysTrue=0;
            int waysFalse=0;
            
           
           for(int k=i+1;k<=j;k=k+2) 
       {
          
           int leftTrue=dp[i][k-1][1];
           int leftFalse=dp[i][k-1][0];
           int rightTrue=dp[k+1][j][1];
           int rightFalse=dp[k+1][j][0];
           
           
           if(S[k]=='&')
           {
              
                   waysTrue+=(leftTrue*rightTrue);
              
                // no of ways the two expression can be evaluated to true is oparand is "&"
                   
               
              
                 waysFalse+=(leftTrue*rightFalse)+(rightTrue*leftFalse)+(leftFalse*rightFalse);
                    // no of ways the two expression can be evaluated to false is oparand is "&"
                   
               
               
           }
           else if(S[k]=='|')
           {
               
                   waysTrue+=(leftTrue*rightFalse)+(rightTrue*leftFalse)+(leftTrue*rightTrue);
                  // no of ways the two expression can be evaluated to true is oparand is "|"
                   
               
              
                  waysFalse+=(leftFalse*rightFalse);
                    // no of ways the two expression can be evaluated to false is oparand is "|"
                   
               
               
               
               
           }
           else if(S[k]=='^')
           { 
              waysTrue+=(leftTrue*rightFalse)+(rightTrue*leftFalse);
              waysFalse+=(leftTrue*rightTrue)+(leftFalse*rightFalse);
                     
           }
           
       
           
           
       }
       
            
            dp[i][j][0]=(dp[i][j][0]%mod)+(waysFalse%mod);
            dp[i][j][1]=(dp[i][j][1]%mod)+(waysTrue%mod);
        }
    }
    
    
    return dp[0][N-1][1];
    
}







    int countWays(int N, string S){
        
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        // int ans=Solve(0,N-1,1,S,dp);
        int ans=Tabulate(N,S);
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
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends