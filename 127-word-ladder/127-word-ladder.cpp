class Solution
{
    public:
        typedef pair<int, string> pq;
    int ladderLength(string source, string target, vector<string> &wordList)
    {

        set<string> collection;

        for (auto eachWord: wordList)
        {
            collection.insert(eachWord);
        }

        queue<string> que;
        int level = 0;
        que.push(source);

        while (!que.empty())
        {
            int currSize = que.size();
            level++;
            for (int it = 0; it < currSize; it++)
            {
                string currWord = que.front();
                que.pop();

                for (int i = 0; i < source.size(); i++)
                {
                    for (char j = 'a'; j <= 'z'; j++)
                    {
                        if(currWord[i] == j)
                            continue;

                        char temp = currWord[i];
                        currWord[i] = j;
                        if (collection.find(currWord) != collection.end())
                        {
                            if (currWord == target)
                                return level + 1;
                            que.push(currWord);
                            collection.erase(currWord);
                        }
                        currWord[i] = temp;
                    }
                }
            }
        }
        return 0;
    }
};