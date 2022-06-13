class Solution {
public:
    int lengthOfLastWord(string a) {
        
        int flag = 0, count = 0;
    for (int j = a.length() - 1; j >= 0; j--)

    {

        if (a[j] == ' ')

        {

            if (flag == 1)
            {
                break;
            }

            continue;
        }

        else
        {
            flag = 1;
            count++;
        }
    }
    return count;

        
        
        
        
        
    }
};