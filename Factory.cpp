#include "Factory.h"

Factory::Factory() : Industrial("Factory")
{
    cout << "Factory created" << endl;
}

Factory::~Factory()
{
    demolish();
    cout << "Factory demolished!" << endl;
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
        if (requestElectricity(700) && requestWater(1200))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    cout << "Factory is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

Building *Factory::clone()
{
    Factory *newFactory = new Factory();
    newFactory->cleanliness = this->cleanliness;
    newFactory->electricityUnits = this->electricityUnits;
    newFactory->waterUnits = this->waterUnits;
    newFactory->value = this->value;
    newFactory->area = this->area;
    newFactory->capacity = this->capacity;

    return newFactory;
}

bool Factory::removeOccupant(Citizen *c)
{
    vector<Citizen *>::iterator first = occupants.begin();
    vector<Citizen *>::iterator last = occupants.end();

    vector<Citizen *>::iterator it = find(first, last, c);
    if (it != last)
    {
        occupants.erase(it);
        cout << "Occupant removed from the Factory" << endl;
        return true;
    }

    cout << "Occupant not in the Factory" << endl;
    return false;
}

bool Factory::isOccupied()
{
    return occupants.size() >0;
}