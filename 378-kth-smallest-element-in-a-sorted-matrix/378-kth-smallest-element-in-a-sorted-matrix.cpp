class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>que;
        int n=matrix.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                que.push(matrix[i][j]);
                
                if(que.size()>k)
                {
                    que.pop();
                }
                
            }
        }
        
        return que.top();
        
    }
};