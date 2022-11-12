class Solution
{
    public:
        vector<vector < string>> answer;
    unordered_map<string,   unordered_set< string>> mpp;
    unordered_map<string, int> levelCount;
    vector<vector < string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

        
        unordered_set<string> stt(wordList.begin(), wordList.end());

        queue<string> que;
        que.push(beginWord);
        levelCount[beginWord] = 0;

        while (!que.empty())
        {

            string word = que.front();
            que.pop();

            for (int j = 0; j < word.size(); j++)
            {
                string original = word;
                for (char k = 'a'; k <= 'z'; k++)
                {

                    word[j] = k;

                    if (stt.find(word) != stt.end())
                    {

                        if (levelCount.find(word) == levelCount.end())

                        {
                            que.push(word);

                            levelCount[word] = levelCount[original] + 1;
                            // mpp[original].insert(word);
                             mpp[word].insert(original);
                        }
                        else if (levelCount[word] == levelCount[original] + 1)
                        {
                            // mpp[original].insert(word);
                             mpp[word].insert(original);
                        }
                    }
                }

                word = original;
            }
        }

        vector<string> recursiveStack;
        DFS(endWord, recursiveStack, beginWord);

        return answer;
    }

    void DFS(string &currWord, vector<string> &recursiveStack, string &beginWord)
    {
        recursiveStack.push_back(currWord);
        if (currWord == beginWord)
        {
            reverse(recursiveStack.begin(),recursiveStack.end());
            answer.push_back(recursiveStack);
             reverse(recursiveStack.begin(),recursiveStack.end());
            recursiveStack.pop_back();
            return;
        }
        for (auto it: mpp[currWord])
        {
            cout<<"here";
            if(levelCount[it]<  levelCount[currWord])
            {
                
                  DFS(it, recursiveStack, beginWord);
            }
        }
        recursiveStack.pop_back();
        return;
    }
};