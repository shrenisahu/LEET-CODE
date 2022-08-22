class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int minHours=0;
        int EnergySum=0;
     
        for(auto i:energy)
            
            
        {
            EnergySum+=i;
        }
        

        if(initialEnergy <=EnergySum)
        minHours=EnergySum-initialEnergy+1;
        cout<<"minHours"<<minHours<<endl;
        int exp=initialExperience;
        int rough=0;
        int temp=0;
       for(auto j:experience)
       {
           
           if(exp <=j)
           {
               rough=j-exp+1;
               exp=exp+rough+j;
               temp+=rough;
               
           }
           else
           {
               exp=exp+j;
           }
           
           
       }
        
       
        
        return minHours+temp;
        
    }
};