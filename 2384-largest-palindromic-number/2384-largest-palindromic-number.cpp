class Solution
{
    public:
        string largestPalindromic(string num)
        {

            unordered_map<char, int> mpp;
            vector<int> arr(10, 0);
            int oddNum = -1;
            string currStr = "";
            for (auto i: num)
            {
                mpp[i]++;
            }

            for (auto i: mpp)
            {
                int key = i.first - '0';
                cout<<key<<"  ";
                int freq = i.second;
                if (freq % 2 != 0)
                {
                    oddNum = max(oddNum, key);
                }

                int quotient = freq / 2;
                arr[key] = quotient;
            }

            for (int i = 9; i >= 0; i--)
            {

                if (arr[i] > 0)
                {
                    if (i == 0 && currStr.size() == 0) continue;
                    int freq = arr[i];
                    int key = '0' + i;
                    char c = (char) key;

                    currStr += string(freq, c);
                }
            }

            string reverseStr = currStr;
            reverse(currStr.begin(), currStr.end());
            cout << currStr;
if(oddNum ==-1)
{
    if(arr[0] >0)
        oddNum=0;
    
}
            string h = to_string(oddNum);
            if (h == "-1")
                reverseStr += currStr;
            else
                reverseStr += h + currStr;

            return reverseStr;
        }
};