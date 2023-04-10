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

                    if (five == 0)
                        return false;
                    ten++;
                    five--;
                }
                else if (bills[i] == 20)
                {

                    if (ten >= 1 && five >= 1)
                    {
                        twenty++;
                        ten--;
                        five--;
                    }
                    else if (five >= 3)
                    {
                        twenty++;

                        five -= 3;
                    }
                    else return false;
                }
            }

            return true;
        }
};