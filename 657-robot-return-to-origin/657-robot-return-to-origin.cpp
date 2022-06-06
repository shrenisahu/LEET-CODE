class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int>dir(4,0);
        // 0  U   1 D   2 L   3 R
        for(auto eachMove:moves)
        {
            if(eachMove=='U') dir[0]++;
            else if (eachMove=='D') dir[1]++;
             else if (eachMove=='L') dir[2]++;
             else if (eachMove=='R') dir[3]++;
        }
        
        
       int UM=dir[0];
       int DM=dir[1];
       int LM=dir[2];
       int RM=dir[3];
        
        cout<<UM<<"  "<<DM<<"  "<<LM<<"  "<<RM<<"  ";
        
        if(UM ==DM && RM ==LM)
            return true;
        
        return false;
    }
};