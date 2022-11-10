//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        set<string>stt(wordList.begin(),wordList.end());
       
        
        queue<pair<string,int>>que;
        stt.erase(startWord);
        que.push({startWord,1});
        
        while(!que.empty())
        {
            auto currPair=que.front();
            que.pop();
            int len=currPair.second;
            string word=currPair.first;
              if(word==targetWord)
                        return len;
            
            for(int i=0;i<word.size();i++)
            {
                 char v=word[i];
                for(char k='a';k<='z';k++)
                {
                   
                    word[i]=k;
                    if(stt.find(word)!=stt.end())
                    {
                      
                        que.push({word,len+1});
                        stt.erase(word);
                    }
                }
                word[i]=v;
            }
        }
        return 0;
    }
    
    
    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends