#include "Monument.h"

Monument::Monument() : Landmark("Monument")
{
}

Monument::~Monument()
{
    demolish();
    cout << "Monument demolished!" << endl;
}

bool Monument::clean()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(40) && useElectricity(10))
        {
            cout << "Monument cleaned." << endl;
            if (cleanliness + 30 >= 100)
            {
                cleanliness = 100;
            }
            else
            {
                if (cleanliness <= 0 && cleanliness + 30 >= 0 && waterUnits > 0 && electricityUnits > 0)
                {
                    delete state;
                    state = new CompleteState();
                    cout << "Monument now in Operational state\n";
                }
                cleanliness += 30;
            }
            return true;
        }

        cout << "Not enough water or electricity to clean the Monument:" << endl;
        cout << "Required water to clean: 40" << endl;
        cout << "Required electricity to clean: 10" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "Monument is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

bool Monument::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        if (occupants.size() < capacity)
        {
            occupants.push_back(c);
            cout << "Occupant added to Monument" << endl;
            return true;
        }
        else
        {
            cout << "Occupant could not be added to Monument, Monument at capacity" << endl;
            return false;
        }
    }

    cout << "Citizen does not exist" << endl;
    return false;
}

bool Monument::removeOccupant(Citizen *c)
{
    vector<Citizen *>::iterator first = occupants.begin();
    vector<Citizen *>::iterator last = occupants.end();

    vector<Citizen *>::iterator it = find(first, last, c);
    if (it != last)
    {
        occupants.erase(it);
        cout << "Occupant removed from the Monument" << endl;
        return true;
    }

    cout << "Occupant not in the Monument" << endl;
    return false;
}

Building *Monument::clone()
{
    Monument *newMonument = new Monument();
    newMonument->cleanliness = this->cleanliness;
    newMonument->electricityUnits = this->electricityUnits;
    newMonument->waterUnits = this->waterUnits;
    newMonument->value = this->value;
    newMonument->area = this->area;
    newMonument->capacity = this->capacity;

    return newMonument;
}

void Monument::demolish()
{
    cout << "Removing everyone from the Monument" << endl;
    occupants.clear();
}
