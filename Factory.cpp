#include "Factory.h"

Factory::Factory() : Industrial("Factory")
{
    // cout << "Factory created" << endl;
}

Building* Factory::clone() {
   
}//Added by Karabo


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
    cout << "Removing everyone from the Factory" << endl;
    occupants.clear();
}

bool Factory::clean(){
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(1200) && useElectricity(700))
        {
            cout << "Factory cleaned.";
            return true;
        }
        cout << "Not enough water or electricity to clean the Factory:" << endl;
        cout << "Required water to clean: 1200" << endl;
        cout << "Required electricity to clean: 700" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "Factory is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

Factory::~Factory(){
    demolish();
    cout << "Factory demolished!" << endl;
}
