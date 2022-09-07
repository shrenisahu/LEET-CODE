class Solution
{
    public:
        vector<string> fizzBuzz(int n)
        {

            vector<string> ans;
            for (int i = 1; i <= n; i++)
            {
                bool flag = false;
                string currStr = "";
                if (i % 3 == 0)
                {
                    currStr += "Fizz";
                    flag = true;
                }

                if (i % 5 == 0)
                {
                    currStr += "Buzz";
                    flag = true;
                }

                if (flag == false)
                    currStr += to_string(i);
                
                ans.push_back(currStr);
            }
            return ans;
        }
};