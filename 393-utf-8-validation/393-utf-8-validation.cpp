class Solution
{
    public:
        bool validUtf8(vector<int> &data)
        {
            int rbytes = 0;
            for (auto val: data)
            {

                if (rbytes == 0)
                {
                    if ((val >> 5) == 0b110)
                    {
                        rbytes = 1;
                    }
                    else if ((val >> 4) == 0b1110)
                    {
                        rbytes = 2;
                    }
                    else if ((val >> 3) == 0b11110)
                    {
                        rbytes = 3;
                    }
                    else if ((val >> 7))
                    {
                        rbytes = 0;
                            return false;
                        continue;
                    }
                    
                }
                else
                {

                    if ((val >> 6) ==0b10)
                
                    rbytes--;
                    else return false;
                }
            }

            return rbytes == 0;
        }
};