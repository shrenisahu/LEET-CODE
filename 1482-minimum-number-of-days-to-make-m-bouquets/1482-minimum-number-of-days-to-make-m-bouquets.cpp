class Solution
{
    public:

        bool isPossible(vector<int> &bloomDay, int m, int k, int days)
        {
            int n = bloomDay.size();
            vector<int> arr(n, 0);

            int currFlow = 0;
            int currBoq = 0;
            for (int i = 0; i < n; i++)
            {
                if (bloomDay[i] <= days)
                {
                    currFlow++;
                }
                else if (bloomDay[i] > days)
                {
                    currFlow = 0;
                }

                if (currFlow == k)
                {
                     currBoq++;
                    currFlow=0;
                }

                if (currBoq == m)
                    return true;
            }
            return false;
        }

    int minDays(vector<int> &bloomDay, int m, int k)
    {

        int start = INT_MAX;
        int end = INT_MIN;
        int n=bloomDay.size();
        
       

        for (auto i: bloomDay)
        {
            start = min(start, i);
            end = max(end, i);
        }
        int ans = 0;

        while (start <= end)

        {

            int mid = start + (end - start) / 2;
            cout<<mid<<" ,";

            if (isPossible(bloomDay, m, k, mid))
            {
                ans = mid;

                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        
        // bool ans2=isPossible(bloomDay, m, k, 12);
        // cout<<" ans"<<ans2<<endl;
        if(ans==0)
            return -1;
        return ans;
    }
};