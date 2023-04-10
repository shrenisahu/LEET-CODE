class Solution
{
    public:
        bool canPlaceFlowers(vector<int> &flowerbed, int n)
        {

            int count = 0;
            int m = flowerbed.size();

            if (m == 1 && flowerbed[0] == 0)
                return true;

            for (int i = 0; i < m; i++)
            {
               	// cout<<"here";
                if (flowerbed[i] == 1)
                {
                    cout << i << ",";
                    i++;

                    continue;
                }
                else if (flowerbed[i] == 0)

                {
                    

                    if (i == 0 && flowerbed[i + 1] == 0)
                    {

                        count++;
                        i++;
                    }
                    else if (i == m - 1 && flowerbed[i - 1] != 1)
                    {
                        count++;
                        i++;
                    }
                    else if  ( i>0 && i<m &&flowerbed[i - 1] != 1 && flowerbed[i + 1] != 1)
                    {
                        count++;
                        i++;
                    }
                   
                }

                if (count == n)
                    return true;
            }

            if (count >= n)
                return true;

            return false;
        }
};