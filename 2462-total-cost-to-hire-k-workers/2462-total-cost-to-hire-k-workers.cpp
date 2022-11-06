class Solution
{
    public:
        long long totalCost(vector<int> &nums, int k, int candidates)
        {
            typedef long long int; 
            long long ans = 0;
            int n = nums.size();
            priority_queue<int, vector < int>, greater < int>> pqFirst;
            priority_queue<int, vector < int>, greater < int>> pqSecond;

            int i = 0;
            int j = n - 1;
            int count = 0;

            while (count < k)
            {
                count++;
                while (pqFirst.size() < candidates && i < j)
                {

                    pqFirst.push(nums[i]);
                    i++;
                }

                while (pqSecond.size() < candidates && (j >= i))
                {

                    pqSecond.push(nums[j]);
                    j--;
                }
                if (pqSecond.size() == 0)
                {

                    ans += pqFirst.top()*1LL;
                    pqFirst.pop();

                    continue;
                }
                if (pqFirst.size() == 0)
                {

                    ans += pqSecond.top()*1LL;
                    pqSecond.pop();

                    continue;
                }

                if (pqFirst.top() <= pqSecond.top())
                {

                    ans += pqFirst.top()*1LL;

                    pqFirst.pop();
                }
                else
                {

                    ans += pqSecond.top()*1LL;

                    pqSecond.pop();
                }
            }

            return ans;
        }
};