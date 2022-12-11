class Solution
{

    vector<vector < int>> dir
    {
        { 1,
            0 },
        { -1,
            0 },
        { 0,
            1 },
        { 0,
            -1 }
    };
    typedef pair<int, pair<int, int>> pq;
    public:
    
    bool isValid(int cr,int cc,int tr,int tc,  vector<vector<int>>&visited)
    {
        if(cr<0 || cc<0 || cr >=tr || cc>=tc || visited[cr][cc]==1)
            return false;
        
        return true;
    }
    
        vector<int> maxPoints(vector<vector < int>> &grid, vector< int > &queries)
        {
            int m=grid.size();
            int n=grid[0].size();
            int k = queries.size();
            vector<vector<int>>visited(m,vector<int>(n,0));
            vector<int> ans(k , 0);
            vector<vector < int>> queryArr;
            for (int i = 0; i< k; i++)
            {
                queryArr.push_back({ queries[i],
                    i });
            }
            sort(queryArr.begin(), queryArr.end());
            priority_queue<pq, vector < pq>, greater < pq>> que;
           
            que.push({ grid[0][0],
                { 0,
                    0 } });
            visited[0][0]=1;
            int count = 0; 

            for (int i = 0; i < k; i++)
            {

                while (que.size() && que.top().first < queryArr[i][0])
                {
                    count++;
                    int currVal=que.top().first;
                    int cr=que.top().second.first;
                    int cc=que.top().second.second;
                    que.pop();
                    for(auto a:dir)
                    {
                        int newRow=cr+a[0];
                        int newCol=cc+a[1];
                        if(isValid(newRow,newCol,m,n,visited))
                        {
                            visited[newRow][newCol]=1;
                            que.push({grid[newRow][newCol],{newRow,newCol}});
                        }
                    }
                }
                ans[ queryArr[i][1]] = count;
            }

            return ans;
        }
};