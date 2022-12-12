class DisjointSet
{
    public:
        vector<int> parent;
    vector<int> rank;
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
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

    int find(int a)
    {
        if (parent[a] == a)
            return a;

        else parent[a] = find(parent[a]);

        return parent[a];
    }
};

class Solution
{
    public:
        vector<vector < string>> accountsMerge(vector<vector < string>> &accounts)
        {
            int n = accounts.size();
            DisjointSet obj(n);

            vector<vector < string>> ans;
            map<string, int> mpp;
            map<int, vector < string>> mpp2;
            for (int i = 0; i < accounts.size(); i++)
            {
                for (int k = 1; k < accounts[i].size(); k++)
                {
                    string currEmail = accounts[i][k];
                    if (mpp.find(currEmail) != mpp.end())
                    {

                        obj.union_(i,mpp[currEmail]);

                    }
                    else
                        mpp[currEmail] = i;
                }
            }

            for (auto it: mpp)
            {
                string mail = it.first;
                int index = it.second;

                int parentIndex = obj.find(index);
                mpp2[parentIndex].push_back(mail);
                
            }
            
            for(auto it:mpp2)
            {
                int index=it.first;
               
                // vector<string>arr=it.second;
                sort(it.second.begin(),it.second.end());
                vector<string>temp;
                temp.push_back(accounts[index][0]);
                for(auto j:it.second)
                {
                    temp.push_back(j);
                }
                 ans.push_back(temp);
                  
            }
            

            return ans;
        }
};