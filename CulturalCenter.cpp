#include "CulturalCenter.h"

CulturalCenter::CulturalCenter() : Landmark("CulturalCenter")
{
}


bool CulturalCenter::clean()
{
    if (useWater(40) && useElectricity(10))
    {
        cout << "CulturalCenter is now clean." << endl;
        return true;
    }
    cout << "CulturalCenter does not have enough water or electricity." << endl;
    return true;
}
