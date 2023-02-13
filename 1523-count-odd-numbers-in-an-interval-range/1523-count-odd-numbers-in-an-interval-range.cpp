class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
       if(low%2==0 && high%2==0)
       {
           int diff=(high-low)/2;
           count=diff;
       }
       else
       {
         int diff=(high-low)/2;
            count=diff+1;
       }
      
        
        return count;
        
    }
};