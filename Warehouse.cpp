#include "Warehouse.h"

Warehouse::Warehouse() : Industrial("Warehouse")
{
}

bool Warehouse::addOccupant(Citizen *c)
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

void Warehouse::demolish(){
    occupants.clear();
}

bool Warehouse::clean(){

    return useWater(500) && useElectricity(300);
}

Warehouse::~Warehouse(){
    demolish();
}
