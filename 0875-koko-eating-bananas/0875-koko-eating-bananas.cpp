class Solution
{
    public:

        bool isPossible(vector<int> &piles, int hours, int speed)
        {

            int n = piles.size();
            int currHours = 0;
            for (int i = 0; i < n; i++)
            {
                int elem = piles[i];
                if (elem < speed)
                    currHours++;

                else
                {
                    int div = elem / speed;

                    currHours += div;

                    if (elem % speed > 0)
                        currHours += 1;
                }

                if (currHours > hours)
                    return false;
            }

            return true;
        }

    int minEatingSpeed(vector<int> &piles, int h)
    {

        int maxElem = 0;
        for (auto i: piles)
        {
            maxElem = max(maxElem, i);
        }

        int start = 1;
        int end = maxElem;
        int ans = 0;

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            if (isPossible(piles, h, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};