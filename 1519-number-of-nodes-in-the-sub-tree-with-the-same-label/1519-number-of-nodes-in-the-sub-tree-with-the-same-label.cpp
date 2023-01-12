class Solution
{
    public:
        unordered_map<char, int> freqMap;
    unordered_map<int, char> mpp;	// index to char
    vector<vector < int>> graph;
    vector<int> ans;
    vector<int> countSubTrees(int n, vector<vector < int>> &edges, string labels)
    {
        ans.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            mpp[i] = labels[i];
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            graph.push_back(temp);
        }
        for (auto it: edges)
        {
            int a = it[0];
            int b = it[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> temp = DFS(0, -1);
        return ans;
    }

    vector<int> DFS(int currVertex, int currPar)
    {

        vector<int> neigh = graph[currVertex];
        vector<int> freq(26, 0);
        for (auto it: neigh)
        {
            if (it == currPar)
                continue;
            vector<int> temp = DFS(it, currVertex);
            for (int i = 0; i < 26; i++)
            {
                freq[i] += temp[i];
            }
        }

        char currChar = mpp[currVertex];
        freq[currChar - 'a']++;
        ans[currVertex] = freq[currChar - 'a'];

        return freq;
    }
};