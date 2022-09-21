class Solution
{
    public:
        vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector< int>> &queries)
        {

            long long n = nums.size();
            long long m = queries.size();
            vector<int> res;
            int sum = 0;
            for (auto &j: nums)
            {
                if (j % 2 == 0)
                    sum += j;
            }

            for (long long i = 0; i < m; i++)
            {

                int index = queries[i][1];
                int val = queries[i][0];

                int ans = nums[index] + val;

                if (ans % 2 == 0)
                {

                    if (nums[index] % 2 == 0)
                    {
                        sum += val;
                    }
                    else
                    {
                        sum += ans;
                    }
                }
                else
                {

                    if (nums[index] % 2 == 0)
                    {
                        sum -= nums[index];
                    }
                }

                nums[index] = ans;

                res.push_back(sum);
            }

            return res;
        }
};