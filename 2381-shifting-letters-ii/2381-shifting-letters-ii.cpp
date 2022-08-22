class Solution
{
    public:
        string shiftingLetters(string s, vector<vector < int>> &shifts)
        {
            int m = s.size();
            int n = shifts.size();
            vector<int> finalShift(m+4, 0);

            cout << endl;
            for (int i = 0; i < n; i++)
            {
                vector<int> eachShift = shifts[i];
                int start = eachShift[0];
                int end = eachShift[1];

                int dir = eachShift[2];
                if (dir == 0)
                {
                    dir = -1;
                }
                finalShift[start] += dir;
                finalShift[end+1]-=dir;
                

               
            }
            
            for(int i=0;i<m+1;i++)
            {
                if(i>0)
                    finalShift[i]+=finalShift[i-1];
            }
            for(int i=0;i<m;i++)
            {
                cout<<finalShift[i]<<"  ";
            }

            for (int i = 0; i < m; i++)
            {
                int temp=(s[i] - 'a' + finalShift[i])%26 ;
                if(temp <0)
                    temp+=26;
                s[i]='a'+temp;
            }

            return s;
        }
};