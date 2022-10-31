// here if we start BFS from  all one simultaneously so when we reach a zero we will not be able to track for which one the answer is ,so its beeter to start with zero,if we start from 0 we dont need to track for which 0 we started beacuse our aim is to reach 1

// TC:O(M*N)

class Solution
{
    public:
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
    vector<vector < int>> updateMatrix(vector<vector < int>> &mat)
    {

        int tr = mat.size();
        int tc = mat[0].size();

        vector<vector < int>> dist(tr, vector<int> (tc, -1));

        queue<vector < int>> que;
        for (int i = 0; i < tr; i++)
        {
            for (int j = 0; j < tc; j++)
            {
                if (mat[i][j] == 0)
                {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(0);
                    que.push(temp);
                }
            }
        }

        while (!que.empty())
        {

            vector<int> arr = que.front();
            que.pop();
            int row = arr[0];
            int col = arr[1];
            int dis = arr[2];

            if (dist[row][col] != -1)
                continue;

            dist[row][col] = dis;

            for (int i = 0; i <= 3; i++)
            {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];
                if (isValid(newRow, newCol, tr, tc, dist))
                {
                    vector<int> num;
                    num.push_back(newRow);
                    num.push_back(newCol);

                    num.push_back(dis + 1);
                    que.push(num);
                }
            }
        }

        return dist;
    }

    bool isValid(int cr, int cc, int tr, int tc, vector<vector < int>> &dist)
    {
        if (cr < 0 || cc < 0 || cr >= tr || cc >= tc || dist[cr][cc] != -1)
            return false;
        return true;
    }
};