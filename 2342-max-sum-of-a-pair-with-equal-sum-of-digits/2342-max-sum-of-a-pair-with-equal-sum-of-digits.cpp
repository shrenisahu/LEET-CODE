class Solution {
public:
    int maximumSum(vector<int>& nums) {
    unordered_map<int,vector<int>>mpp;
        int maxAns=-1;
        int maxSum=-1;
       for(int i=0;i<nums.size();i++)
       {
           int currNum=nums[i];
           int currSum=findSum(currNum);
          
           mpp[currSum].push_back(currNum);
       }
        
         for(auto temp:mpp)
        
    {
        int key=temp.first;
        vector<int>collection=temp.second;
             if(collection.size() >1 )
             {
                 vector<int>Arr=mpp[key];
                  sort(Arr.begin(),Arr.end(),greater<int>());
                   int hover=Arr[0]+Arr[1];
                 maxSum=max(maxSum,hover);
                 
             }
       
             
    }
        if(maxSum==-1)
            return -1;
        
     
        
        return maxSum;
        
    }
    
   
    
    int findSum(int num)
    {
        int sum=0;
        while(num>0)
            
        {
            int mod=num%10;
            sum+=mod;
            num=num/10;
        }
        
        return sum;
    }
};