#include "Park.h"

Park::Park():Landmark("Park")
{

}

Park::~Park()
{
    demolish();
    cout << "Park demolished!" << endl;
}


bool Park::clean()
{
    if(useWater(40) && useElectricity(10)){
        cout << "Park is now clean." << endl;
        return true;
    }
    cout << "Park does not have enough water or electricity." << endl;
    return true;
}

bool Park::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        if (occupants.size() < capacity)
        {
            occupants.push_back(c);
            cout << "Occupant added to Park" << endl;
            return true;
        }
        else
        {
            cout << "Occupant could not be added to Park, Park at capacity" << endl;
            return false;
        }
    }

    cout << "Citizen does not exist" << endl;
    return false;
}

bool Park::removeOccupant(Citizen *c)
{
    vector<Citizen *>::iterator first = occupants.begin();
    vector<Citizen *>::iterator last = occupants.end();

    vector<Citizen *>::iterator it = find(first, last, c);
    if (it != last)
    {
        occupants.erase(it);
        cout << "Occupant removed from the Park" << endl;
        return true;
    }

    cout << "Occupant not in the Park" << endl;
    return false;
}

Building *Park::clone()
{
    Park *newPark = new Park();
    newPark->cleanliness = this->cleanliness;
    newPark->electricityUnits = this->electricityUnits;
    newPark->waterUnits = this->waterUnits;
    newPark->value = this->value;
    newPark->area = this->area;
    newPark->capacity = this->capacity;

    return newPark;
}

void Park::demolish()
{
    cout << "Removing everyone from the Park" << endl;
    occupants.clear();
}

