class Solution
{

    vector<vector < int>> dir = {
		{ 1,
            0 },
        { -1,
            0 },
        { 0,
            1 },
        { 0,
            -1 }
    };
    public:
        vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
        {

            int m = image.size();
            int n = image[0].size();
            int currValue = image[sr][sc];
            if (currValue == color)
                return image;

            BFS(sr, sc, m, n, color, image, currValue);
            return image;
        }

    void BFS(int currRow, int currCol, int m, int n, int color, vector<vector < int>> &image, int currValue)

    {
        queue<pair<int, int>> que;
        que.push({ currRow,
            currCol });

        while (!que.empty())
        {
            auto currPair = que.front();
            que.pop();

            int row = currPair.first;
            int col = currPair.second;
            cout << "here";
            image[row][col] = color;

            for (int i = 0; i <= 3; i++)
            {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];

                if (isValid(newRow, newCol, m, n, image, color, currValue))
                {

                    que.push({ newRow,
                        newCol });
                }
            }

           
        }
         return;
    }

    bool isValid(int cr, int cc, int tr, int tc, vector<vector < int>> &image, int color, int currValue)
    {
        if (cr < 0 || cr >= tr || cc < 0 || cc >= tc || image[cr][cc] != currValue)
        {

            return false;
        }

        return true;
    }
};