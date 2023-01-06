class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(),costs.end());
        int count=0;
        for(int i=0;i<costs.size();i++)
        {
            if(costs[i] <=coins)
            {
                count+=1;
                coins-=costs[i];
            }
            else break;
        }
        return count;
    }
};