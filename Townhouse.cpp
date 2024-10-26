#include "Townhouse.h"

Townhouse::Townhouse():Residential("Townhouse"){

}

Townhouse ::~Townhouse(){
    occupants.clear();
}

void Townhouse::demolish()
{
    // must call destructor
}

bool Townhouse::useShower()
{
    return useWater(100) && useElectricity(50);
}

bool Townhouse::useToilet()
{
    return useWater(16);
}

bool Townhouse::useStove()
{
    return useElectricity(58);
}

bool Townhouse::clean()
{
    return useWater(300) && useElectricity(70);
}

bool Townhouse::addOccupant(Citizen *c)
{
    if (c != nullptr && occupants.size() < capacity)
    {
        occupants.push_back(c);
        return true;
    }

    return false;
}