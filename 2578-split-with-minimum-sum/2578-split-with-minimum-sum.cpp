class Solution
{
    public:
        int splitNum(int num)
        {

            vector<int> arr;

            while (num > 0)
            {
                int rem = num % 10;
                arr.push_back(rem);
                num = num / 10;
            }
            int n=arr.size();
            sort(arr.begin(), arr.end());
            
            int n1=0,n2=0;
            
            for(int i=0;i<n;i=i+2)
            {
                n1=n1*10 +arr[i];
            }
             for(int i=1;i<n;i=i+2)
            {
                n2=n2*10 +arr[i];
             }
            
            return n1+n2;
        }
};