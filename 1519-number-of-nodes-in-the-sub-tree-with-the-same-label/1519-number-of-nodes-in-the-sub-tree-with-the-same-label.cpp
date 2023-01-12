class Solution
{
    public:

        vector<vector < int>> graph;
    vector<int> ans;
    vector<int> countSubTrees(int n, vector<vector < int>> &edges, string labels)
    {
        ans.resize(n, 0);
        graph.resize(n);

        for (auto it: edges)
        {
            int a = it[0];
            int b = it[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> temp = DFS(0, -1, labels);
        return ans;
    }

    vector<int> DFS(int currVertex, int currPar, string &labels)
    {

        vector<int> neigh = graph[currVertex];
        vector<int> freq(26, 0);
        for (auto it: neigh)
        {
            if (it == currPar)
                continue;
            vector<int> temp = DFS(it, currVertex, labels);
            for (int i = 0; i < 26; i++)
            {
                freq[i] += temp[i];
            }
        }

        char currChar = labels[currVertex];
        freq[currChar - 'a']++;
        ans[currVertex] = freq[currChar - 'a'];

        return freq;
    }
};