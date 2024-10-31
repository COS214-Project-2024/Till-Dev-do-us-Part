#include "Warehouse.h"

Warehouse::Warehouse() : Industrial("Warehouse")
{
    // cout << "Warehouse created!"  << endl;
}

Building* Warehouse::clone(){
    return new Warehouse();
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

    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(500) && useElectricity(300))
        {
            cout << "Warehouse cleaned.";
            return true;
        }
        cout << "Not enough water or electricity to clean the Warehouse:" << endl;
        cout << "Required water to clean: 500" << endl;
        cout << "Required electricity to clean: 300" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "Warehouse is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

Warehouse::~Warehouse(){
    demolish();
    cout << "Warehouse demolished!" << endl;
}
