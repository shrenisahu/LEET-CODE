class Solution {
public:
    
    
bool checkIsVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {

        return true;
    }
    return false;
}
    string reverseVowels(string s) {
         int i = 0;
    int j = s.length() - 1;

    while (i <= j)
    {

        if (checkIsVowel(s[i]) && checkIsVowel(s[j]))
        {

            swap(s[i], s[j]);
            i++;
            j--;
        }

        else if (checkIsVowel(s[i]) && checkIsVowel(s[j]) == false)
        {
            j--;
        }

        else if (checkIsVowel(s[j]) && checkIsVowel(s[i]) == false)
        {
            i++;
        }

        else if (checkIsVowel(s[j]) == false && checkIsVowel(s[i]) == false)

        {
            i++;
            j--;
        }
    }



return s;
    }
};