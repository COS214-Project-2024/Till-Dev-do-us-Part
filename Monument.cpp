#include "Monument.h"

Monument::Monument() : Landmark("Monument")
{
}


bool Monument::clean()
{
    if (useWater(40) && useElectricity(10))
    {
        cout << "Monument is now clean." << endl;
        return true;
    }
    
    cout << "Monument does not have enough water or electricity." << endl;
    return true;
}
