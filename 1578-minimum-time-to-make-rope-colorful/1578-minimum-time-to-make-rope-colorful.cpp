class Solution
{
    public:
        int minCost(string colors, vector<int> &neededTime)
        {
           
               
            int lastVal = neededTime[0];
            char lastColor = colors[0];
            int ans = 0;
            int i = 1;
            while (i < colors.size())

            {
                char currColor = colors[i];
                int currVal = neededTime[i];

                if (currColor == lastColor)
                {
                    if (currVal >= lastVal)
                    {
                        ans += lastVal;
                        lastVal = currVal;
                    }
                    else
                    {
                        ans += currVal;
                    }
                }
                else
                {
                    lastVal = neededTime[i];
                    lastColor = colors[i];
                }
                i++;
            }

            return ans;
        }
};