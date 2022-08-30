class Solution
{
    public:
        vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
        {
            int n = nums.size();
            int m = queries.size();
            vector<int> prefix(n);
            vector<int> arr(m);
           
            sort(nums.begin(),nums.end());
            prefix[0] = nums[0];

            for (int i = 1; i < n; i++)
            {
                prefix[i] = prefix[i - 1] + nums[i];
                cout<<prefix[i]<<" ";
            }
            for(int i=0;i<m;i++)
            {
                 int ans=0;
                int query=queries[i];
                for(int j=0;j<n;j++)
                {
                    if(prefix[j]<=query)
                        ans=j+1;
                    else break;
                }
                arr[i]=ans;
            }
            return arr;
        }
};