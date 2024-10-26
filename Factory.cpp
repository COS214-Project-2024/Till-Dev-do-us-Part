#include "Factory.h"

Factory::Factory() : Industrial("Factory")
{
}

bool Factory::addOccupant(Citizen *c)
{
    if (c != nullptr && occupants.size() < capacity)
    {
        occupants.push_back(c);
        cout << "Occupant added";
        return true;
    }

    cout << "Could not add occupant. Building at capacity";
    return false;
}

void Factory::demolish(){
    occupants.clear();
}

bool Factory::clean(){
    return useWater(1200) && useElectricity(700);
}

Factory::~Factory(){
    demolish();
}
