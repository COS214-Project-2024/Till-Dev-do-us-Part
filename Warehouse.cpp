#include "Warehouse.h"

Warehouse::Warehouse() : Industrial("Warehouse")
{
    cout << "Warehouse created!"  << endl;
}

Warehouse::~Warehouse()
{
    delete this->state;
    state = nullptr;
    demolish();
    cout << "Warehouse demolished!" << endl;
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
        if (requestElectricity(300) && requestWater(500))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    cout << "Warehouse is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

Building *Warehouse::clone()
{
    Warehouse *newWarehouse = new Warehouse();
    newWarehouse->cleanliness = this->cleanliness;
    newWarehouse->electricityUnits = this->electricityUnits;
    newWarehouse->waterUnits = this->waterUnits;
    newWarehouse->value = this->value;
    newWarehouse->area = this->area;
    newWarehouse->capacity = this->capacity;

    return newWarehouse;
}

bool Warehouse::removeOccupant(Citizen *c)
{
    vector<Citizen *>::iterator first = occupants.begin();
    vector<Citizen *>::iterator last = occupants.end();

    vector<Citizen *>::iterator it = find(first, last, c);
    if (it != last)
    {
        occupants.erase(it);
        cout << "Occupant removed from the Warehouse" << endl;
        return true;
    }

    cout << "Occupant not in the Warehouse" << endl;
    return false;
}

bool Warehouse::isOccupied()
{
    return occupants.size() > 0;
}