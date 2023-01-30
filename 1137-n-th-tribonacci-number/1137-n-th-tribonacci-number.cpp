class Solution
{
    public:
        int tribonacci(int n)
        {

            int x = 0;
            int y = 1;
            int z = 1;

            if (n == 0)
                return 0;
            if (n == 1 || n == 2)
                return 1;

            for (int i = 3; i <= n; i++)
            {
                int c = x + y + z;

                x = y;
                y = z;
                z = c;
            }

            return z;
        }
};