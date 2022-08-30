class Solution
{
    public:
        bool findRotation(vector<vector < int>> &mat, vector< vector< int>> &target)
        {

            int n = mat.size();

            if (mat == target)
                return true;
          
            for (int loop = 1; loop <= 3; loop++)
            {
                  vector<vector < int>> arr(n, vector<int> (n));
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {  
                        arr[j][n-1-i] =mat[i][j];
                    }
                }
                mat=arr;
                if(arr==target)
                    return true;
            }
            return false;
        }
};