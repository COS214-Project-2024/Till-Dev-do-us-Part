#include "CulturalCenter.h"

CulturalCenter::CulturalCenter() : Landmark("CulturalCenter")
{
}

CulturalCenter::~CulturalCenter()
{
    delete this->state;
    state = nullptr;
    demolish();
    cout << "Cultural Center demolished!" << endl;
}


bool CulturalCenter::clean()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(40) && useElectricity(10))
        {
            cout << "CulturalCenter cleaned." << endl;
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
                    cout << "CulturalCenter now in Operational state\n";
                }
                cleanliness += 30;
            }
            return true;
        }

        cout << "Not enough water or electricity to clean the CulturalCenter:" << endl;
        cout << "Required water to clean: 40" << endl;
        cout << "Required electricity to clean: 10" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "CulturalCenter is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

bool CulturalCenter::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        if (occupants.size() < capacity)
        {
            occupants.push_back(c);
            cout << "Occupant added to CulturalCenter" << endl;
            return true;
        }
        else
        {
            cout << "Occupant could not be added to CulturalCenter, CulturalCenter at capacity" << endl;
            return false;
        }
    }

    cout << "Citizen does not exist" << endl;
    return false;
}

bool CulturalCenter::removeOccupant(Citizen *c)
{
    vector<Citizen *>::iterator first = occupants.begin();
    vector<Citizen *>::iterator last = occupants.end();

    vector<Citizen *>::iterator it = find(first, last, c);
    if (it != last)
    {
        occupants.erase(it);
        cout << "Occupant removed from the CulturalCenter" << endl;
        return true;
    }

    cout << "Occupant not in the CulturalCenter" << endl;
    return false;
}

Building *CulturalCenter::clone()
{
    CulturalCenter *newCulturalCenter = new CulturalCenter();
    newCulturalCenter->cleanliness = this->cleanliness;
    newCulturalCenter->electricityUnits = this->electricityUnits;
    newCulturalCenter->waterUnits = this->waterUnits;
    newCulturalCenter->value = this->value;
    newCulturalCenter->area = this->area;
    newCulturalCenter->capacity = this->capacity;

    return newCulturalCenter;
}

void CulturalCenter::demolish()
{
    cout << "Removing everyone from the CulturalCenter" << endl;
    occupants.clear();
}