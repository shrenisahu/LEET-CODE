class Solution
{
    public:
        int kthSmallest(vector<vector < int>> &matrix, int k)
        {
            int n = matrix.size();
            int start = matrix[0][0];
            int end = matrix[n - 1][n - 1];

            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                // int temp = getSmallerNumbers(mid);
                if (getSmallerNumbers(mid,matrix) < k)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }

            return start;
        }
    
    
    int getSmallerNumbers(int mid,vector<vector < int>> &matrix)
    {
        int n=matrix.size();
        int count=0;
        int j=n-1;
        
        for(int i=0;i<n;i++)
        {
            while(j>=0 && matrix[i][j] >mid)
                j--;
            
              count+=j+1;
        }
      return count;
    }
};