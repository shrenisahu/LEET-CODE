class Solution {
public:
    bool detectCapitalUse(string word) {
        int smallCount=0;
        int capitalCount=0;
        
        for(auto i:word)
        {
            int a=i;
            if(a<=90 && a>=65)
            {
                capitalCount+=1;
            }
            else  if(a>90 )
            {
                smallCount+=1;
            }
        }
        int b=word[0];
      // cout<<smallCount<<","<<capitalCount<<" ,"<<b<<endl;
            if(smallCount>0 && capitalCount>1 )
            return false;
          if(smallCount>0 && capitalCount==1  && b >90 )
            return false;
        
        return true;
        
    }
};