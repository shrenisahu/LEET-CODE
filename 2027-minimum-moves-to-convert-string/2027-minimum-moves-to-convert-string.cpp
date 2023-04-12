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

                    moves++;
                    i += 3;
                }
            }
            return moves;
        }
};