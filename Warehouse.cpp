#include "Warehouse.h"

Warehouse::Warehouse() : Industrial("Warehouse")
{
    cout << "Warehouse created!"  << endl;
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
    cout << "Removing everyone from the warehouse" << endl;
    occupants.clear();
    cout << "Everyone removed from the warehouse" << endl;
}

bool Warehouse::clean(){

    return useWater(500) && useElectricity(300);
}

Warehouse::~Warehouse(){
    demolish();
    cout << "Warehouse demolished!" << endl;
}
