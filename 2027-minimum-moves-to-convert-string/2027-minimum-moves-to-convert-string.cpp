class Solution
{
    public:
        int minimumMoves(string s)
        {

            int n = s.size();
            int i = 0;
            int moves = 0;
            while (i < n)
            {
                int x_count = 0;

                if (s[i] == 'O')
                {
                    // cout << "here";
                    i++;
                    continue;
                }
                else
                {
                    if (i < n)
                    {
                        int first = s[i];
                        if (first == 'X')
                            x_count++;
                    }
                    if (i + 1 < n)
                    {
                        int second = s[i + 1];
                        if (second == 'X')
                            x_count++;
                    }
                    if (i + 2 < n)
                    {
                        int third = s[i + 2];
                        if (third == 'X')
                            x_count++;
                    }

                    if (x_count > 0)
                        moves++;
                    i += 3;
                }
            }
            return moves;
        }
};