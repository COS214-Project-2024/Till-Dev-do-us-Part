#include "Factory.h"

Factory::Factory() : Industrial("Factory")
{
    cout << "Factory created" << endl;
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
    cout << "Removing everyone from the Factory" << endl;
    occupants.clear();
}

bool Factory::clean(){
    if(this->state->useWater() && this->state->useElectricity()){
        if (useWater(1200) && useElectricity(700)){
            cout << "Factory cleaned!" << endl;
            return true;
        }
    }
    return false;
}

Factory::~Factory(){
    demolish();
    cout << "Factory demolished!" << endl;
}
