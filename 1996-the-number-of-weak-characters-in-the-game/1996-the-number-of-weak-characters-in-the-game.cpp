class Solution
{
    public:
    static bool compare(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
    
        int numberOfWeakCharacters(vector<vector < int>> &properties)
        {
            int weakPoint = 0;
            sort(properties.begin(), properties.end(),compare);
 int n = properties.size();
            int maxDefence = properties[n-1][1];

           

            for (int i = n - 2; i >= 0; i--)
            {
                int defence = properties[i][1];
                if (maxDefence > defence)
                {
                    weakPoint++;
                }

                maxDefence = max(maxDefence, properties[i][1]);
            }

            return weakPoint;
        }
};