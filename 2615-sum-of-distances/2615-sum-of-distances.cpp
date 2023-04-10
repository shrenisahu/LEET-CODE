class Solution
{
    public:
        vector < long long > distance(vector<int> &nums)
        {
            long long n = nums.size();
            vector < long long > ans(n, 0);

            unordered_map < long long int, vector < long long int>> mpp;

            for (long long i = 0; i < nums.size(); i++)
            {
                long long curr = nums[i];
                mpp[curr].push_back(i);
            }
           
            
            for(auto it:mpp)
            {
                int elem=it.first;
                vector< long long int>arr=it.second;
                int m=arr.size();
                
                
                
                 vector<long long> pre(m+1);
            for (int j=0;j<m;j++)
                pre[j+1]=pre[j]+it.second[j];
                // here we are making m+1 size array so that when idx=0 doing arr[idx-1] doest goes out of bound
                // 0 0 2 5
                
                for(int idx=0;idx<m;idx++)
                {
                    
                    
                    long long  suffixSumTillIdx=pre.back()-pre[idx+1];
                      long long  prefixSumBeforeIdx=pre[idx];
                      long long  numberOfsmallerElem=idx;
                      long long  numberOfGreaterElem=m-idx-1;
                    ans[arr[idx]]=(arr[idx]*numberOfsmallerElem -prefixSumBeforeIdx)+(suffixSumTillIdx-arr[idx]*(numberOfGreaterElem));
                    
                    // (that particular indx elem *no of elements smaller than it before it)-prefix sum till before that index
                    
                    // +
                    //[suffix sum till that index - (index elem*no of elements gretare than it)]
                }
            }

            

            return ans;
        }
};