#include "Mall.h"

/**
 * @file Mall.cpp
 * @brief Implementation of the Mall class, representing a collection of commercial buildings.
*/

/**
 * @brief Constructs a Mall object with default values.
*/
Mall::Mall() : Commercial("Mall")
{
    area = 40000;
    value = 350000;
    capacity = 15;
}

/**
 * @brief Adds a building to the Mall if capacity allows.
 *
 * @param building Pointer to the Commercial building to be added.
 * @return true if the building was successfully added, false otherwise.
*/
bool Mall::addBuilding(Commercial *building)
{
    if (building != nullptr)
    {
        if (building->getType() == "Mall")
        {
            cout << "Cannot add a Mall to a Mall" << endl;
            return false;
        }
        else
        {
            if (noBuildings + 1 <= capacity)
            {
                stores.push_back(building);
                noBuildings++;
                value += building->getValue();
                waterUnits += building->getWater();
                electricityUnits += building->getElectricity();
                cleanliness = (cleanliness + building->getCleanliness()) / noBuildings;
                cout << "Building added to the Mall" << endl;
                return true;
            }
            else
            {
                cout << "Could not build, not enough land/space" << endl;
                return false;
            }
        }
    }
    cout << "Cannot add non-existent building to the Mall" << endl;
    return false;
}

/**
 * @brief Removes a building from the Mall.
 *
 * @param building Pointer to the Commercial building to be removed.
 * @return true if the building was successfully removed, false otherwise.
 */
bool Mall::removeBuilding(Commercial *building)
{
    vector<Commercial *>::iterator first = stores.begin();
    vector<Commercial *>::iterator last = stores.end();

    vector<Commercial *>::iterator it = find(first, last, building);
    if (it != last)
    {
        stores.erase(it);
        value -= building->getValue();
        waterUnits -= building->getWater();
        electricityUnits -= building->getElectricity();
        cleanliness = (cleanliness - building->getCleanliness()) / noBuildings;
        building = nullptr;
        noBuildings--;
        cout << "Building removed from the Mall" << endl;
        return true;
    }

    cout << "Building not in the Mall" << endl;
    return false;
}

/**
 * @brief Demolishes all buildings in the Mall and clears the stores list.
 */
void Mall::demolish()
{
    cout << "====Demolishing buildings in the Mall====" << endl;
    for (int i = 0; i < stores.size(); ++i)
    {
        delete stores.at(i);
        stores[i] = nullptr;
    }
    stores.clear();
    cout << "Demolished all buildings in the Mall" << endl;
}

/**
 * @brief Cleans all buildings in the Mall.
 *
 * @return true if all buildings were successfully cleaned, false if any could not be cleaned.
 */
bool Mall::clean()
{
    int count = 0;
    int accumCleanliness = 0;
    for (vector<Commercial *>::iterator it = stores.begin(); it != stores.end(); ++it)
    {
        if (!(*it)->clean())
        {
            cout << "Building " << (*it) << " could not be cleaned (not enough water or electricity)" << endl;
            return false;
        }
        count++;
        accumCleanliness += (*it)->getCleanliness();
    }
    cleanliness = accumCleanliness / count;
    cout << "All buildings in " << this << " were cleaned";
    return true;
}

/**
 * @brief Adds a citizen as an occupant to one of the buildings in the Mall.
 *
 * @param c Pointer to the Citizen to be added.
 * @return true if the citizen was successfully added, false if all buildings are at capacity.
 */
bool Mall::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        for (vector<Commercial *>::iterator it = stores.begin(); it != stores.end(); it++)
        {
            if ((*it)->addOccupant(c))
            {
                cout << "Citizen added to Mall\n";
                return true;
            }
        }
        cout << "Citizen could not be added to Mall, all buildings at capacity\n";
        return false;
    }

    cout << "Citizen is non-existent\n";
    return false;
}

/**
 * @brief Removes a citizen occupant from the Mall.
 *
 * @param c Pointer to the Citizen to be removed.
 * @return true if the occupant was successfully removed, false if not found.
 */
bool Mall::removeOccupant(Citizen *c)
{
    for (vector<Commercial *>::iterator it = stores.begin(); it < stores.end(); it++)
    {
        if ((*it)->removeOccupant(c))
        {
            cout << "Occupant removed!\n";
            return true;
        }
    }
    cout << "Occupant not found in any of the buildings in the mall\n";
    return false;
}

/**
 * @brief Creates a clone of the Mall object.
 *
 * @return A pointer to a new Building object that is a clone of the Mall.
 */
Building *Mall::clone()
{
    Mall *newBuilding = new Mall();
    newBuilding->area = this->area;
    newBuilding->capacity = this->capacity;
    for (vector<Commercial *>::iterator it = stores.begin(); it != stores.end(); it++)
    {
        newBuilding->addBuilding((Commercial *)(*it)->clone());
    }
    newBuilding->cleanliness = this->getCleanliness();
    newBuilding->electricityUnits = this->getElectricity();
    newBuilding->waterUnits = this->getWater();
    newBuilding->state = this->state->clone();
    return newBuilding;
}

/**
 * @brief Calculates and returns the cleanliness of the Mall.
 *
 * @return The average cleanliness of all buildings in the Mall.
 */
float Mall::getCleanliness()
{
    int count = 0;
    int accumCleanliness = 0;
    for (vector<Commercial *>::iterator it = stores.begin(); it != stores.end(); ++it)
    {
        accumCleanliness += (*it)->getCleanliness();
        count++;
    }
    cleanliness = accumCleanliness / count;
    return cleanliness;
}

/**
 * @brief Calculates and returns the total water usage of the Mall.
 *
 * @return The total water units used by all buildings in the Mall.
 */
float Mall::getWater()
{
    int accumWater = 0;
    for (vector<Commercial *>::iterator it = stores.begin(); it != stores.end(); ++it)
    {
        accumWater += (*it)->getWater();
    }
    waterUnits = accumWater;
    return waterUnits;
}

/**
 * @brief Calculates and returns the total electricity usage of the Mall.
 *
 * @return The total electricity units used by all buildings in the Mall.
 */
float Mall::getElectricity()
{
    int accumElec = 0;
    for (vector<Commercial *>::iterator it = stores.begin(); it != stores.end(); ++it)
    {
        accumElec += (*it)->getElectricity();
    }
    electricityUnits = accumElec;
    return electricityUnits;
}

/**
 * @brief Returns the number of buildings currently in the Mall.
 *
 * @return The number of buildings in the Mall.
 */
int Mall::getNoBuildings()
{
    return noBuildings;
}

/**
 * @brief Destroys the Mall object, releasing resources and demolishing all buildings.
 */
Mall::~Mall()
{
    delete this->state;
    state = nullptr;
    demolish();
    cout << "Destroyed the Mall\n";
}

/**
 * @brief Checks if all buildings in the Mall are occupied.
 *
 * @return true if all buildings are occupied, false if any building is not occupied.
 */
bool Mall::isOccupied()
{
    for (vector<Commercial *>::iterator it = stores.begin(); it < stores.end(); it++)
    {
        if (!(*it)->isOccupied())
        {
            return false;
        }
    }
    return true;
}
