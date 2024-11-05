#include "Plant.h"

/**
 * @brief Constructs a Plant object, initializing its properties.
 */
Plant::Plant() : Industrial("Plant")
{
    area = 4000;     ///< Set the area of the plant.
    capacity = 15;   ///< Set the maximum capacity of buildings in the plant.
    value = 100000;  ///< Set the initial value of the plant.
    noBuildings = 0; ///< Initialize the number of buildings in the plant.
    cout << "Plant created" << endl;
}

/**
 * @brief Destroys the Plant object, demolishing all buildings within it.
 */
Plant::~Plant()
{
    demolish(); ///< Demolish the plant and free resources.
    cout << "Plant demolished" << endl;
}

/**
 * @brief Adds a building to the plant.
 *
 * @param building A pointer to the Industrial building to be added.
 * @return true if the building was successfully added, false otherwise.
 */
bool Plant::addBuilding(Industrial *building)
{
    if (building != nullptr)
    {
        if (building->getType() == "Plant")
        {
            cout << "Cannot add a Plant to a Plant" << endl;
            return false; ///< Prevent adding a Plant to itself.
        }
        else
        {
            if (noBuildings + 1 <= capacity)
            {
                buildings.push_back(building); ///< Add the building to the list.
                noBuildings++;
                value += building->getValue();                                          ///< Update the total value.
                waterUnits += building->getWater();                                     ///< Update water units.
                electricityUnits += building->getElectricity();                         ///< Update electricity units.
                cleanliness = (cleanliness + building->getCleanliness()) / noBuildings; ///< Update cleanliness.
                cout << "Building added to the Plant" << endl;
                return true;
            }
            else
            {
                cout << "Could not build, not enough land/space" << endl;
                return false; ///< Not enough capacity to add the building.
            }
        }
    }
    cout << "Cannot add non-existent building to the Plant" << endl;
    return false; ///< The building pointer was null.
}

/**
 * @brief Removes a building from the plant.
 *
 * @param building A pointer to the Industrial building to be removed.
 * @return true if the building was successfully removed, false otherwise.
 */
bool Plant::removeBuilding(Industrial *building)
{
    vector<Industrial *>::iterator first = buildings.begin();
    vector<Industrial *>::iterator last = buildings.end();

    vector<Industrial *>::iterator it = find(first, last, building);
    if (it != last)
    {
        buildings.erase(it);                                                    ///< Remove the building from the list.
        value -= building->getValue();                                          ///< Update the total value.
        waterUnits -= building->getWater();                                     ///< Update water units.
        electricityUnits -= building->getElectricity();                         ///< Update electricity units.
        cleanliness = (cleanliness - building->getCleanliness()) / noBuildings; ///< Update cleanliness.
        building = nullptr;                                                     ///< Clear the pointer to the building.
        noBuildings--;                                                          ///< Decrease the building count.
        cout << "Building removed from the Plant" << endl;
        return true;
    }

    cout << "Building not in the Plant" << endl;
    return false; ///< The building was not found in the list.
}

/**
 * @brief Demolishes all buildings in the plant.
 */
void Plant::demolish()
{
    cout << "Clearing and demolishing all the buildings in the Plant:" << endl;
    for (int i = 0; i < buildings.size(); ++i)
    {
        delete buildings.at(i); ///< Free memory for each building.
        buildings[i] = nullptr; ///< Clear the pointer.
    }
    buildings.clear(); ///< Clear the vector of buildings.
    cout << "Demolished all buildings in the Plant" << endl;
}

/**
 * @brief Cleans all buildings in the plant.
 *
 * @return true if all buildings were cleaned, false otherwise.
 */
bool Plant::clean()
{
    bool cleanedAll = true;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if (!(*it)->clean())
        {                       ///< Attempt to clean each building.
            cleanedAll = false; ///< If any building fails to clean, set flag to false.
        }
    }

    if (!cleanedAll)
    {
        cout << "Could not clean all buildings" << endl;
        return false; ///< At least one building could not be cleaned.
    }

    cout << "Cleaned all buildings in the Plant" << endl;
    return true;
}

/**
 * @brief Adds an occupant to a building within the plant.
 *
 * @param c A pointer to the Citizen to be added as an occupant.
 * @return true if the occupant was successfully added, false otherwise.
 */
bool Plant::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if ((*it)->getType() == type && (*it)->addOccupant(c))
            { ///< Check type and add occupant.
                cout << "Occupant added to building " << (*it) << endl;
                return true; ///< Occupant added successfully.
            }
        }

        cout << "Citizen could not be added to Plant, all buildings at capacity\n";
        return false; ///< All buildings are at capacity.
    }

    cout << "All " << type << " buildings in the Plant are at capacity" << endl;
    return false; ///< The Citizen pointer was null.
}

/**
 * @brief Removes an occupant from a building within the plant.
 *
 * @param c A pointer to the Citizen to be removed.
 * @return true if the occupant was successfully removed, false otherwise.
 */
bool Plant::removeOccupant(Citizen *c)
{
    for (vector<Industrial *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if ((*it)->removeOccupant(c))
        { ///< Attempt to remove occupant.
            cout << "Occupant removed!\n";
            return true; ///< Occupant removed successfully.
        }
    }
    cout << "Occupant not found in any of the buildings in the Plant\n";
    return false; ///< The occupant was not found.
}

/**
 * @brief Clones the plant, creating a deep copy of it.
 *
 * @return A pointer to the cloned Plant object.
 */
Building *Plant::clone()
{
    Plant *newBuilding = new Plant(); ///< Create a new Plant object.
    newBuilding->area = this->area;
    newBuilding->capacity = this->capacity;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        newBuilding->addBuilding((Industrial *)(*it)->clone()); ///< Clone each building.
    }
    newBuilding->cleanliness = this->getCleanliness();
    newBuilding->electricityUnits = this->getElectricity();
    newBuilding->waterUnits = this->getWater();
    newBuilding->state = this->state->clone(); ///< Clone the state.
    return newBuilding;                        ///< Return the cloned Plant.
}

/**
 * @brief Gets the average cleanliness of all buildings in the plant.
 *
 * @return The average cleanliness value.
 */
float Plant::getCleanliness()
{
    int count = 0;
    int accumCleanliness = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumCleanliness += (*it)->getCleanliness(); ///< Accumulate cleanliness.
        count++;
    }
    cleanliness = accumCleanliness / count; ///< Calculate average cleanliness.
    return cleanliness;
}

/**
 * @brief Gets the total water units used by all buildings in the plant.
 *
 * @return The total water units.
 */
float Plant::getWater()
{
    int accumWater = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumWater += (*it)->getWater(); ///< Accumulate total water units.
    }
    waterUnits = accumWater; ///< Update waterUnits.
    return waterUnits;
}

/**
 * @brief Gets the total electricity units used by all buildings in the plant.
 *
 * @return The total electricity units.
 */
float Plant::getElectricity()
{
    int accumElec = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumElec += (*it)->getElectricity(); ///< Accumulate total electricity units.
    }
    electricityUnits = accumElec; ///< Update electricityUnits.
    return electricityUnits;
}

/**
 * @brief Checks if all buildings in the plant are occupied.
 *
 * @return true if all buildings are occupied, false otherwise.
 */
bool Plant::isOccupied()
{
    for (vector<Industrial *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if (!(*it)->isOccupied())
        { ///< If any building is not occupied, return false.
            return false;
        }
    }

    return true; ///< All buildings are occupied.
}

/**
 * @brief Gets the number of buildings in the plant.
 *
 * @return The number of buildings.
 */
int Plant::getNoBuildings()
{
    return noBuildings; ///< Return the number of buildings in the Plant.
}
