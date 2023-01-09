class Solution
{
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
        {
            int n = gas.size();
            int currGas = 0;
            int totalGas = 0;
            int totalCost = 0;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {

                currGas += gas[i] - cost[i];
                totalGas += gas[i];
                totalCost += cost[i];
                if (currGas < 0)
                {
                    currGas = 0;
                    ans = i + 1;
                }
            }

            if (totalGas < totalCost)
                return -1;

            return ans;
        }
};