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
                char letter2 = s[n - i -1];
                
                cout<<letter<<" ,"<<letter2<<endl;
                if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'A' || letter == 'I' || letter == 'O' || letter == 'E' || letter == 'U')
                    count1++;

                if (letter2 == 'a' || letter2 == 'e' || letter2 == 'i' || letter2 == 'o' || letter2 == 'u' || letter2 == 'A' || letter2 == 'I' || letter2 == 'O' || letter2 == 'E' || letter2 == 'U')
                    count2++;
            }

            return count1 == count2;
        }
};