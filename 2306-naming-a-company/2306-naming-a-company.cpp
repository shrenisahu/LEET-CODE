// The solution goes as such that we create a  26 sets of strings.each set deontes the alphabet order.now traverse the ideas array and at the firstletter of each word put it in the set.remove the first letter and then put it into the set.now the logic here is consider we are comparing elements of two sets.if both the sets have coomon elements then they cannot form a pair.so coutn the common words.now calculate the total valid  pair that can be created
    
    // how to find total pair created 
    //(set_A.size()*set_B.size() )
    // now total valid pairs
    //(set_A.size()-commonElemCount *set_B.size()-commonElemCount )
    // now the pair can be reversed as weel so again multiply by two
    //(set_A.size()-commonElemCount *set_B.size()-commonElemCount ) *2


class Solution
{

    public:

        long long distinctNames(vector<string> &ideas)
        {

            unordered_set<string> suffixes[26];
            long long ans = 0;
            for (auto &i: ideas)
            {
                char start = i[0];
                int temp = start - 97;
                int m = i.size();
                string halfWord = i.substr(1, m - 1);

                suffixes[temp].insert(halfWord);
            }
            for (int i = 0; i < 25; i++)

            {

                for (int j = i + 1; j < 26; j++)
                {
                    int count = 0;

                    for (auto &eachSetWord: suffixes[i])
                    {
                        if (suffixes[j].find(eachSetWord) != suffixes[j].end())

                        {

                            count++;
                        }
                    }

                    int temp = (suffixes[i].size() - count) *(suffixes[j].size() - count) *2;
                    ans += temp;
                }
            }

            return ans;
        }
};