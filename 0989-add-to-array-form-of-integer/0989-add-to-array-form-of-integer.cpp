class Solution
{
    public:

        vector<int> addIntegers(vector<int> &arr, int k)
        {
            vector<int> ans;
            int n = arr.size();
            int carry = 0;
            int i = n - 1;
           
            while (i >= 0 && k > 0)
            {

                int rem = k % 10;
                int temp = arr[i] + rem+carry;
                int addRem = temp % 10;
                carry = temp / 10;

                ans.push_back(addRem);
                k = k / 10;
                i--;
            }

            while (i >= 0)
            {

                int temp = arr[i] + carry;
                int addRem = temp % 10;
                ans.push_back(addRem);
                carry = temp / 10;
                i--;
            }

            while (k > 0)
            {
                int temp = k % 10;
                int add = temp + carry;
               
                int rem = add % 10;
                carry = add / 10;
                ans.push_back(rem);

                k = k / 10;
            }
            while(carry>0)
            {
                int temp=carry%10;
                
                 ans.push_back(temp);
                carry=carry/10;
            }
           
            reverse(ans.begin(), ans.end());
            return ans;
        }

    vector<int> addToArrayForm(vector<int> &num, int k)
    {

        vector<int> ans = addIntegers(num, k);
        return ans;
    }
};