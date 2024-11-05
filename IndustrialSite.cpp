#include "IndustrialSite.h"

/**
 * @brief Constructs a new IndustrialSite object with default values.
 */
IndustrialSite::IndustrialSite() : Industrial("IndustrialSite")
{
    area = 50000;    ///< Set the area of the industrial site.
    capacity = 50;   ///< Set the maximum capacity of buildings in the industrial site.
    noBuildings = 0; ///< Initialize the number of buildings to zero.
    value = 12000;   ///< Set the initial value of the industrial site.
}

/**
 * @brief Loads a specified amount of electricity to all buildings in the industrial site.
 *
 * @param units The amount of electricity to load.
 */
void IndustrialSite::loadElectricity(float units)
{
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        (*it)->requestElectricity(units);
        electricityUnits += units;
    }
}

/**
 * @brief Loads a specified amount of water to all buildings in the industrial site.
 *
 * @param units The amount of water to load.
 */
void IndustrialSite::loadWater(float units)
{
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        (*it)->requestWater(units);
        waterUnits += units;
    }
}

/**
 * @brief Uses a specified amount of electricity across all buildings.
 *
 * @param units The amount of electricity to use.
 * @return true if all buildings successfully used the electricity, false otherwise.
 */
bool IndustrialSite::useElectricity(float units)
{
    if (this->state->canUseElectricity())
    {
        electricityUnits = 0;
        bool usedAll = true;
        for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if (!(*it)->useElectricity(units))
            {
                usedAll = false;
            }
            electricityUnits += (*it)->getElectricity();
        }

        if (!usedAll)
            cout << "Could not use " << units << " of electricity in all the buildings\n";
        else
            cout << "Used " << units << " of electricity in all the buildings\n";

        return usedAll;
    }
    cout << "The Industrial Site is in the " << this->state->getName() << " and cannot use electricity on any buildings" << endl;
    return false;
}

/**
 * @brief Uses a specified amount of water across all buildings.
 *
 * @param units The amount of water to use.
 * @return true if all buildings successfully used the water, false otherwise.
 */
bool IndustrialSite::useWater(float units)
{
    if (this->state->canUseWater())
    {
        this->waterUnits = 0;
        bool usedAll = true;
        for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if (!(*it)->useWater(units))
            {
                usedAll = false;
            }
            waterUnits += (*it)->getWater();
        }

        if (!usedAll)
            cout << "Could not use " << units << " units of water in all the buildings\n";
        else
            cout << "Used " << units << " units of water in all the buildings\n";

        return usedAll;
    }

    cout << "The Industrial Site is in the " << this->state->getName() << " and cannot use water on any buildings" << endl;
    return false;
}

/**
 * @brief Gets the price of the industrial site.
 *
 * @return The value of the industrial site.
 */
float IndustrialSite::getPrice()
{
    return value;
}

/**
 * @brief Gets the type of the industrial site.
 *
 * @return The type as a string.
 */
string IndustrialSite::getType()
{
    return type;
}

/**
 * @brief Demolishes all buildings in the industrial site and frees associated resources.
 */
void IndustrialSite::demolish()
{
    cout << "Demolishing all the buildings in the IndustrialSite\n";
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        value -= (*it)->getValue();
        waterUnits -= (*it)->getWater();
        electricityUnits -= (*it)->getElectricity();
        delete (*it);
        (*it) = nullptr;
        noBuildings--;
    }

    cout << "Demolished all the buildings in the IndustrialSite\n";
}

/**
 * @brief Cleans all buildings in the industrial site using water and electricity if available.
 *
 * @return true if all buildings were successfully cleaned, false otherwise.
 */
bool IndustrialSite::clean()
{
    if (state->canUseElectricity() && state->canUseWater())
    {
        cleanliness = 0;
        waterUnits = 0;
        electricityUnits = 0;
        bool usedAll = true;
        for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if (!(*it)->clean())
            {
                usedAll = false;
            }
            cleanliness += (*it)->getCleanliness();
            waterUnits += (*it)->getWater();
            electricityUnits += (*it)->getElectricity();
        }

        if (!usedAll)
            cout << "Could not clean all the buildings\n";
        else
            cout << "Cleaned all the buildings\n";

        cleanliness /= buildings.size();
        return usedAll;
    }

    cout << "The Suburb is in the " << this->state->getName() << " and cannot use water or electricity on any buildings" << endl;
    return false;
}

/**
 * @brief Adds a citizen to one of the buildings in the industrial site.
 *
 * @param c The citizen to add.
 * @return true if the citizen was successfully added, false otherwise.
 */
bool IndustrialSite::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if ((*it)->addOccupant(c))
            {
                return true;
            }
        }
    }

    return false;
}

/**
 * @brief Destroys the IndustrialSite, cleans up resources and demolishes all buildings.
 */
IndustrialSite::~IndustrialSite()
{
    demolish();
    cout << "Destroyed the IndustrialSite\n";
}

/**
 * @brief Adds a building to the industrial site.
 *
 * @param building The building to add.
 * @return true if the building was successfully added, false otherwise.
 */
bool IndustrialSite::addBuilding(Industrial *building)
{
    if (building != nullptr)
    {
        if (building->getType() == "Plant")
        {
            int plantBuildings = ((Plant *)building)->getNoBuildings();
            if (plantBuildings + noBuildings <= capacity)
            {
                buildings.push_back(building);
                noBuildings += plantBuildings;
                value += building->getValue();
                waterUnits += building->getWater();
                electricityUnits += building->getElectricity();
                cout << "Plant added to the Industrial Site" << endl;
                return true;
            }
            else
            {
                cout << "Plant could not be added to the Industrial Site" << endl;
                return false;
            }
        }
        else
        {
            if (noBuildings + 1 <= capacity)
            {
                buildings.push_back(building);
                noBuildings++;
                value += building->getValue();
                waterUnits += building->getWater();
                electricityUnits += building->getElectricity();
                cleanliness = (cleanliness + building->getCleanliness()) / noBuildings;
                cout << "Building added to the Industrial Site" << endl;
                return true;
            }
            else
            {
                // cout << "Building could not be added to the Industrial Site" << endl;
                return false;
            }
        }
    }

    cout << "Building is non-existent" << endl;
    return false;
}

/**
 * @brief Removes a building from the industrial site.
 *
 * @param building The building to remove.
 * @return true if the building was successfully removed, false otherwise.
 */
bool IndustrialSite::removeBuilding(Industrial *building)
{
    vector<Industrial *>::iterator first = buildings.begin();
    vector<Industrial *>::iterator last = buildings.end();

    vector<Industrial *>::iterator it = find(first, last, building);
    if (it != last)
    {
        buildings.erase(it);
        value -= building->getValue();
        waterUnits -= building->getWater();
        electricityUnits -= building->getElectricity();
        cleanliness = (cleanliness - building->getCleanliness()) / noBuildings;
        delete building;
        building = nullptr;
        noBuildings--;
        cout << "Building removed from the Industrial Site" << endl;
        return true;
    }

    cout << "Building not in the Industrial Site" << endl;
    return false;
}

/**
 * @brief Removes a citizen from one of the buildings in the industrial site.
 *
 * @param c The citizen to remove.
 * @return true if the citizen was successfully removed, false otherwise.
 */
bool IndustrialSite::removeOccupant(Citizen *c)
{
    for (vector<Industrial *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if ((*it)->removeOccupant(c))
        {
            cout << "Citizen removed\n";
            return true;
        }
    }

    cout << "Citizen was not found in any of the buildings in the IndustrialSite\n";
    return false;
}

/**
 * @brief Clones the IndustrialSite, creating a new instance with the same properties.
 *
 * @return A pointer to the cloned IndustrialSite.
 */
Building *IndustrialSite::clone()
{
    IndustrialSite *newBuilding = new IndustrialSite();

    newBuilding->area = this->area;
    newBuilding->capacity = this->capacity;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        newBuilding->addBuilding((Industrial *)(*it)->clone());
    }
    newBuilding->cleanliness = this->getCleanliness();
    newBuilding->electricityUnits = this->getElectricity();
    newBuilding->waterUnits = this->getWater();
    newBuilding->state = this->state->clone();
    return newBuilding;
}

/**
 * @brief Gets the cleanliness level of the industrial site.
 *
 * @return The average cleanliness of the buildings.
 */
float IndustrialSite::getCleanliness()
{
    int accumCleanliness = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumCleanliness += (*it)->getWater();
    }
    cleanliness = accumCleanliness / buildings.size();
    return cleanliness;
}

/**
 * @brief Gets the total amount of water used by all buildings.
 *
 * @return The total water units.
 */
float IndustrialSite::getWater()
{
    int accumWater = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumWater += (*it)->getWater();
    }
    waterUnits = accumWater;
    return accumWater;
}

/**
 * @brief Gets the total amount of electricity used by all buildings.
 *
 * @return The total electricity units.
 */
float IndustrialSite::getElectricity()
{
    int accumElec = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumElec += (*it)->getElectricity();
    }
    electricityUnits = accumElec;
    return accumElec;
}

/**
 * @brief Gets the number of buildings in the industrial site.
 *
 * @return The number of buildings.
 */
int IndustrialSite::getNoBuildings()
{
    return noBuildings;
}

/**
 * @brief Checks if the industrial site is occupied by any buildings.
 *
 * @return true if no buildings are occupied, false otherwise.
 */
bool IndustrialSite::isOccupied()
{
    for (vector<Industrial *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if ((*it)->isOccupied())
        {
            return false;
        }
    }

    return true;
}
