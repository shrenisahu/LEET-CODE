class Solution
{
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
        {

            int n = gas.size();
            int start=0;
            int totalGas=0;
            int totalCost=0;
            int currGas=0;

            for (int i = 0; i < n; i++)
            {
                currGas+=gas[i]-cost[i];
                totalGas+=gas[i];
                totalCost+=cost[i];
                if(currGas <0)
                {
                    start=i+1;
                    currGas=0;
                }
                    
               
                
                
            }
            if(totalCost>totalGas)
                return -1;
            
            return start;
        }
};