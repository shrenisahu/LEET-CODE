class Solution
{
    public:
        string shiftingLetters(string s, vector<int> &shifts)
        {
            int n = s.size();

            int temp = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                temp = (temp + shifts[i]) % 26;

                shifts[i] = temp;
            }

            for (int i = 0; i < s.size(); i++)
            {
                s[i] = ((s[i] - 'a' + shifts[i]) % 26) + 'a';
               	//phele 'a ' anr char ke bich ka distance nikalo phir.us distance mein shifts[i] add karo now take mod with 26 .
               	// s[i]-'a';
               	//s[i]-'a'+shifts[i];
               	//(s[i]-'a'+shifts[i]) %26    --- eqn 1
               	//now we will get how many steps we want to move from that char but we want from 'a'so 
                // eqn 1 + 'a' 
                }
            return s;
        }
};