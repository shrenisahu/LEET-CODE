class Solution
{
    public:
        bool halvesAreAlike(string s)
        {

            int n = s.size();
            map<char, int> mpp;
            int count1 = 0;
            int count2 = 0;
            for (int i = 0; i < n / 2; i++)
            {
                char letter = s[i];
                if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'A' || letter == 'I' || letter == 'O' || letter == 'E' || letter == 'U')
                    count1++;

            }
             for (int i = n/2; i < n ; i++)
            {
                char letter = s[i];
                if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'A' || letter == 'I' || letter == 'O' || letter == 'E' || letter == 'U')
                    count2++;

            }
            
            return count1==count2;
        }
};