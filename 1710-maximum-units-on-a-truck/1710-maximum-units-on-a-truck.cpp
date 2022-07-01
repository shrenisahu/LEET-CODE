class Solution {
public:
   static  bool sortCol(const vector<int>& v1,const vector<int>& v2) { 
     return v1[1] > v2[1]; 
} 
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
     sort(boxTypes.begin(),boxTypes.end(),sortCol);
      int ans=0;
        
       for(auto eachBox:boxTypes)
       {
           int units=eachBox[1];
           int boxes=eachBox[0];
           // if(truckSize==0)
           //     return ans;
           if(truckSize>=boxes)
           {
               ans=ans+(units*boxes);
               truckSize-=boxes;
               
               
           }
           else 
           {
               ans+=(truckSize*units);
               return ans;
           }
           
       }
        
        return ans;
    }
    
   
};

