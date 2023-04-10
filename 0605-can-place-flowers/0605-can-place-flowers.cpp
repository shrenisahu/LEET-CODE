class Solution
{
    public:
        bool canPlaceFlowers(vector<int> &flowerbed, int n)
        {

            flowerbed.insert(flowerbed.begin(), 0);
            flowerbed.push_back(0);
            int m = flowerbed.size();
            int count = 0;
            for (int i = 1; i < m - 1; i++)

            {

                if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
                {
                    count++;
                    i++;
                }
            }
            if (count >= n)
                return true;

            return false;
        }
};