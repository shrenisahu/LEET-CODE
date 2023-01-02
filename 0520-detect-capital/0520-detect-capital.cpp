class Solution
{
    public:
        bool detectCapitalUse(string word)
        {
            int n = word.size();

            bool capitalOne = false;
            bool capitalTwo = false;
            bool smallOne = false;
            bool smallTwo = false;
            int pos = -1000;

            for (int i = 0; i < n; i++)
            {
                int a = word[i];
                if (a >= 91)
                {
                    if (smallOne == true)

                        smallTwo = true;

                    else
                        smallOne = true;
                }
                else if (a >= 65 && a<=90)
                {
                    if (capitalOne == true)

                        capitalTwo = true;

                    else
                    {
                        capitalOne = true;
                        pos = i;
                    }
                }
            }

          
            if (capitalTwo == true && smallOne == true)
                return false;
            if(capitalOne==true && (smallOne==true || smallTwo==true) && pos!=0)
                return false;
             

            return true;
        }
};