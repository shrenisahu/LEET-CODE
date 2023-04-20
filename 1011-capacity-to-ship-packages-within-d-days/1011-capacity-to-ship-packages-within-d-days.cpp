class Solution
{
    public:

        bool isPossible(vector<int> &weights, int days, int capacity)
        {
            int n = weights.size();

            int currSum = 0;
            int currDays = 1;
            for (int i = 0; i < n; i++)
            {
                int elem = weights[i];
                currSum += elem;

                if (currSum > capacity)
                {
                    currDays++;
                    currSum = elem;
                }

                if (currDays > days)
                {

                    return false;
                }
            }

            return true;
        }

    int shipWithinDays(vector<int> &weights, int days)
    {

        int totalSum = 0;
        int maxElem = 0;
        int n = weights.size();

        for (int i = 0; i < n; i++)
        {

            totalSum += weights[i];
            maxElem = max(maxElem, weights[i]);
        }

        int start = maxElem;
        int end = totalSum;

        int ans = 0;
        
        while (start <= end)
        {
            int mid = (start + end) / 2;

          
            if (isPossible(weights, days, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }
};