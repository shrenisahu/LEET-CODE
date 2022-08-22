class Solution
{
    public:
        int characterReplacement(string s, int k)
        {

            int n = s.size();
            int maxL = 0;
            for (char i = 'A'; i <= 'Z'; i++)
            {
                char currChar = i;
                int flipCount=0;
                int release=0;

                for (int i = 0; i < n ;i++) {
                     
                     if(s[i]!=currChar){
                         flipCount++;
                     }
                         
                    if(flipCount==k+1)
                    {
                        while(flipCount >k)
                        {
                            if (s[release]!=currChar)
                                flipCount--;
                            
                            release++;
                            
                        }
                    }
                     
                    maxL=max(maxL,i-release+1);
                     
                     }
                }
            return maxL;
            }
        };