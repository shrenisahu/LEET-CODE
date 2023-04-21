class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {

            int minElem = arr.front();
            int maxElem = arr.back();
            
            unordered_set<int>stt;
            
            for(auto it:arr)
                stt.insert(it);
            int ans=0;
            int countK=0;
            
            for(int i=1;i<=maxElem;i++)
            {
                
                if(stt.find(i)==stt.end())
                {

                    countK++;
                  
                    if(countK==k)
                    {
                        return i;
                    }
                }
                
            }
            
            int diff=k-countK;
            ans=maxElem+diff;
            
            
            return ans;
        }
};