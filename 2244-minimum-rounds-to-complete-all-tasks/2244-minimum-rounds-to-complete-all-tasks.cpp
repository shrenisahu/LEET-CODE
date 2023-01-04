class Solution
{
    public:
        int minimumRounds(vector<int> &tasks)
        {

            sort(tasks.begin(), tasks.end());
            unordered_map<int, int> mpp;
            int count = 0;
            for (auto i: tasks)
            {
                mpp[i]++;
            }

            for (auto it: mpp)
            {
                int elem = it.first;
                int freq = it.second;
                if(freq==1)
                    return -1;
                if (freq % 3 == 0)
                {
                    count += (freq / 3);
                    cout<<count;
                }

                else if (freq % 3 == 2)
                {
                    count += (freq / 3) + 1;
                }
                else if (freq % 3 == 1)
                {
                    freq = freq - 4;
                    count += 2;
                    
                    count += (freq / 3);
                }
                
                // cout<<count<<" ,";
            }
            return count;
        }
};