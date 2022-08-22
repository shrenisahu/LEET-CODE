not
class Solution
{
public:
int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
{
​
int n = energy.size();
int energyInc = 0;
int expInc = 0;
int rough = 0;
int temp = 0;
for (int i = 0; i < n; i++)
{
​
if (energy[i] >= initialEnergy)
{
rough = energy[i] - initialEnergy + 1;
initialEnergy += rough;
initialEnergy = initialEnergy - energy[i];
energyInc += rough;
}
if (experience[i] >= initialExperience)
{
temp = experience[i] - initialExperience + 1;
cout << "temp" << experience[i] << "  " << initialExperience << "  " << temp << endl;
initialExperience += temp;
initialExperience += experience[i];
expInc += temp;
}
else if (energy[i] < initialEnergy && experience[i] < initialExperience)
{
initialExperience += experience[i];
initialEnergy -= energy[i];
}
}
cout<<"eneg"<<expInc;
return expInc + energyInc;
}
};