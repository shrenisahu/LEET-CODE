class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
        
        int sum=0;
        for(auto i:arr)
        {
            sum+=i;
            
        }
        int n=arr.size();
        if(sum%3!=0)
            return false;
        int target=sum/3;
        
        int count=0;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            curr+=arr[i];
            if(curr==target)
            {
                count++;
                curr=0;
            }
        }
        
        if(count>=3)
            return true;
        
        return false;
        
    }
};