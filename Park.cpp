#include "Park.h"

Park::Park() : Landmark("Park")
{
    area = 600;
    capacity = 25;
    value = 30000;
}

/**
 * @brief Destructor for the Park class.
 * Calls the demolish method to clear the park and logs its demolition.
 */
Park::~Park()
{
    demolish();
    cout << "Park demolished!" << endl;
}

/**
 * @brief Cleans the park by using water and electricity.
 *
 * @return true if the park was successfully cleaned, false otherwise.
 */
bool Park::clean()
{
    if (useWater(40) && useElectricity(10))
    {
        cout << "Park is now clean." << endl;
        return true;
    }
    cout << "Park does not have enough water or electricity." << endl;
    return false; // Changed return value to false when not enough resources.
}

/**
 * @brief Adds a citizen to the park as an occupant.
 *
 * @param c A pointer to the Citizen to be added.
 * @return true if the citizen was successfully added, false if the park is at capacity or if the citizen is null.
 */
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

/**
 * @brief Removes a citizen from the park.
 *
 * @param c A pointer to the Citizen to be removed.
 * @return true if the citizen was successfully removed, false if the citizen is not found.
 */
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

/**
 * @brief Clones the park, creating a deep copy of it.
 *
 * @return A pointer to the cloned Park object.
 */
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

/**
 * @brief Demolishes the park, removing all occupants.
 */
void Park::demolish()
{
    cout << "Removing everyone from the Park" << endl;
    occupants.clear();
}
