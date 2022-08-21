class Solution
{
    public:
        int minimumRecolors(string blocks, int k)
        {

            int i = 0;
            int release = 0;
            int Wcount = 0;
            int minCount = 102;
            for (int i = 0; i < blocks.size(); i++)
            {

                if (blocks[i] == 'W')
                    Wcount++;
                if (i - release + 1 == k)
                {
                    minCount = min(minCount, Wcount);

                    if (blocks[release] == 'W')
                    {
                        Wcount--;
                        
                    }
                    release++;
                }
            }
            return minCount;
        }
};