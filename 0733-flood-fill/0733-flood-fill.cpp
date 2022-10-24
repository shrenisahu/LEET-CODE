class Solution
{
    public:
        vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
        {

            int m = image.size();
            int n = image[0].size();
            int currValue = image[sr][sc];
            if(currValue==color)
                return image;
            DFS(sr, sc, m, n, color, image, currValue);
            return image;
        }

    void DFS(int currRow, int currCol, int m, int n, int color, vector<vector < int>> &image, int currValue)

    {
        if (currRow < 0 || currCol < 0 || currRow >= m || currCol >= n || image[currRow][currCol] != currValue)
            return;

        image[currRow][currCol] = color;

        DFS(currRow + 1, currCol, m, n, color, image, currValue);
        DFS(currRow - 1, currCol, m, n, color, image, currValue);
        DFS(currRow, currCol + 1, m, n, color, image, currValue);
        DFS(currRow, currCol - 1, m, n, color, image, currValue);
        return;
    }
};