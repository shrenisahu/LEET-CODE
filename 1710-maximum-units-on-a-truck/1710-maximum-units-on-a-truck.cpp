class Solution
{
    public:

        static bool comp(vector<int> &a, vector<int> &b)
        {

            if (b[1] < a[1])
                return true;

            return false;
        }
    int maximumUnits(vector<vector < int>> &boxTypes, int truckSize)
    {

        sort(boxTypes.begin(), boxTypes.end(), comp);
        int ans = 0;
        for (auto i: boxTypes)
        {
            int boxType = i[0];
            int units = i[1];

            if (truckSize >= boxType)
            {
                truckSize -= boxType;
                ans += (boxType *units);
            }
            else
            {
                ans += (truckSize *units);
                break;
            }
        }

        return ans;
    }
};