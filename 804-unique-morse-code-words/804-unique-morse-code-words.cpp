class Solution
{
    public:
        int uniqueMorseRepresentations(vector<string> &words)
        {
            unordered_set<string> set;
            vector<string> arr(26);
            arr= { ".-",
                "-...",
                "-.-.",
                "-..",
                ".",
                "..-.",
                "--.",
                "....",
                "..",
                ".---",
                "-.-",
                ".-..",
                "--",
                "-.",
                "---",
                ".--.",
                "--.-",
                ".-.",
                "...",
                "-",
                "..-",
                "...-",
                ".--",
                "-..-",
                "-.--",
                "--.." };
            
            
            for(auto eachWord:words)
            {
                string currStr="";
                for(auto eachLetter:eachWord)
                {
                    int num=eachLetter-'a';
                    string mapStr=arr[num];
                    currStr+=mapStr;
                }
                set.insert(currStr);
                currStr="";
            }
            return set.size();
            
        }
};