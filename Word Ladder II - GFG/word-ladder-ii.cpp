//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
       vector<vector < string>> ans;

            set<string> stt(wordList.begin(), wordList.end());
            vector<string> usedWord;
            queue<vector < string>> que;
            que.push({ beginWord });
            stt.erase(beginWord);
            while (!que.empty())
            {
                int size = que.size();
                usedWord.clear();
                for (int i = 0; i < size; i++)
                {

                    vector<string> currList = que.front();
                    que.pop();
                    string word = currList.back();
                    if (word == endWord)
                    {

                        ans.push_back(currList);
                    }

                    for (int j = 0; j < word.size(); j++)
                    {
                        char original = word[j];
                        for (char k = 'a'; k <= 'z'; k++)
                        {
                            word[j] = k;
                            if (stt.find(word) != stt.end())
                            {
                               	// cout<<"here  "<<word<<endl;
                                usedWord.push_back(word);
                                currList.push_back(word);

                                que.push(currList);
                                currList.pop_back();
                            }
                        }
                        word[j] = original;
                    }
                }
                for (auto it: usedWord)
                {
                   	// cout << it << ", ";
                    stt.erase(it);
                }
               	// cout << endl;
            }
            return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends