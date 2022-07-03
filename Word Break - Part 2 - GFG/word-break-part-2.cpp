// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string>ans;
        int start=0;
        
       
         map<string,int> stt;
        for(auto i : dict){
            stt.insert({i,1});
        }
      
        Break(0,ans,stt,"",s);
        return ans;
    }
    
    void Break(int index,vector<string>&ans, map<string,int> &stt,string currStr,string s)
    {
        if(index>=s.size())
        {
            
            currStr.pop_back();
            ans.push_back(currStr);
        }
        
        for(int i=index;i<s.size();i++)
        {
            string currWord=s.substr(index,i-index+1);
            if(stt.find(currWord)!=stt.end())
            {
               
                Break(i+1,ans,stt,currStr+currWord+" ",s);
            }
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends