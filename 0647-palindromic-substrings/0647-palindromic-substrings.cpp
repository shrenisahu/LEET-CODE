class Solution
{
    public:

        bool isPalindrome(string s, int start, int end)

    {
        while (start <= end)
        {
            if (s[start] != s[end])

                return false;
            end--;
            start++;
        }
        return true;
    }
    int countSubstrings(string s)
    {

        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {

            for (int j = i; j < n; j++)
            {

                bool ans = isPalindrome(s, i, j);
                if (ans) count++;
            }
        }

        return count;
    }
};