class Solution
{
    public:
        bool lemonadeChange(vector<int> &bills)
        {

            int five = 0;
            int ten = 0;
            int twenty = 0;

            int n = bills.size();

            for (int i = 0; i < n; i++)
            {
                if (bills[i] == 5)
                    five++;

                else if (bills[i] == 10)
                {

                    if ( five== 0)
                        return false;
                    ten++;
                    five--;
                }
                else if (bills[i] == 20)
                {

                    if (five == 0 && ten == 0)
                        return false;
                    if (ten == 0 && five <= 2)
                        return false;
                    if (five == 0)
                        return false;
                    twenty++;

                    if (ten >= 1 && five >= 1)
                    {
                        ten--;
                        five--;
                    }
                    else if (five >= 3)
                    {
                        five -= 3;
                    }
                }
            }

            return true;
        }
};