class Solution
{
    public:
        int countWays(vector<vector < int>> &ranges)
        {
           	// if we found how my groups then total ans=2 ^ groups
            sort(ranges.begin(), ranges.end());
            int n = ranges.size();
           
            int group = 1;
            int  largest = ranges[0][1];
            
            
            for(auto i:ranges)
            {
                int s=i[0];
                int e=i[1];
                
                if(largest<s)
                {
                   group++;
                    largest=e;
                    
                    
                }
                else largest=max(largest,e);
                    
            }
          

            int ans = 1;

           for(int i = 0; i < group; i++)
            {
                ans = (ans *2) % 1000000007;
            }

            
            return ans;
        }
};