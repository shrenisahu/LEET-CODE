class DisjointSet
{

    public:
        vector<int> parent;
    vector<int> rank;
    public:
        DisjointSet(int V)
        {
            parent.resize(V + 1);
            rank.resize(V, 0);
            for (int i = 0; i < V; i++)
            {
                parent[i] = i;
            }
        }

    int find(int a)
    {
        if (parent[a] == a)
            return a;

        else parent[a] = find(parent[a]);

        return parent[a];
    }
    void union_(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);

        if (parA == parB)
            return;

        if (rank[parA] > rank[parB])
        {
            parent[parB] = parA;
        }
        else if (rank[parA] < rank[parB])
        {
            parent[parA] = parB;
        }
        else
        {
            parent[parA] = parB;
            rank[parB] += 1;
        }
    }
};
class Solution
{
    public:

        int makeConnected(int n, vector<vector < int>> &connections)
        {
            int ans = 0;
            int disConnected = 0;
            int extra=0;
            int noOfEdges = connections.size();
            DisjointSet obj(n);

            if (noOfEdges < n - 1)
                return -1;

            for (auto i: connections)
            {

                auto src = i[0];
                auto dest = i[1];

                int parSrc = obj.find(src);
                int parDest = obj.find(dest);

                if (parSrc != parDest)
                    obj.union_(src, dest);
                else  extra++;
            }

            for (int i = 0; i < n; i++)
            {
                if (obj.parent[i] == i)
                    disConnected++;
            }
             if(extra >=disConnected - 1)
                 return disConnected - 1;
            

            return -1;
        }
};