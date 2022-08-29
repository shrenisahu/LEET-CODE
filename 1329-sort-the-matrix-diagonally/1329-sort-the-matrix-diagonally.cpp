class Solution
{

    public:

        vector<vector < int>> Solve(vector<vector < int>> &mat)
        {

            int m = mat.size();
            int n = mat[0].size();
            vector<vector < int>> ans(m, vector<int> (n, 0));

            for (int col = 0; col <= n - 1; col++)
            {
                vector<int> sortMatrix;
                int row = 0;
                int tempC = col;
                while (row <= m - 1 && tempC <= n - 1)
                {
                    int currElem = mat[row][tempC];

                    sortMatrix.push_back(currElem);

                    row++;
                    tempC++;
                }

                sort(sortMatrix.begin(), sortMatrix.end());

                int row1 = 0;
                int tempC1 = col;
                int idx = 0;
                while (row1 <= m - 1 && tempC1 <= n - 1)
                {

                    ans[row1][tempC1] = sortMatrix[idx];
                    idx++;
                    row1++;
                    tempC1++;
                }
            }

            for (int row = 1; row <= m - 1; row++)
            {
                vector<int> sortMatrix;
                int col = 0;
                int tempR = row;

                while (col <= n - 1 && tempR <= m - 1)
                {
                    int currElem = mat[tempR][col];
                   	// cout<<"["<<tempR<<","<<col<<"]  ="<<currElem<<"  ,";
                    sortMatrix.push_back(currElem);

                    col++;
                    tempR++;
                }

                sort(sortMatrix.begin(), sortMatrix.end());

                int col1 = 0;
                int tempR1 = row;
                int idx = 0;
                while (col1 <= n - 1 && tempR1 <= m - 1)
                {

                    ans[tempR1][col1] = sortMatrix[idx];

                    col1++;
                    tempR1++;
                    idx++;
                }
            }
            return ans;
        }

    vector<vector < int>> diagonalSort(vector<vector < int>> &mat)
    {

        vector<vector < int>> ans = Solve(mat);
        return ans;
    }
};