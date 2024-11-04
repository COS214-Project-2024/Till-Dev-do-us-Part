#include "Building.h"
#include "ResourceDepartment.h"

/**
 * @brief Constructs a Building object with the specified type and initializes default values.
 * @param type The type of the building (e.g., "House").
 * @author Katlego
 * */
Building::Building(string type)
{
    state = new ConstructionState();
    this->type = type;
    this->cleanliness = 100;
    electricityUnits = 0;
    waterUnits = 0;
}

/**
 * @brief Destructor for the Building class. Cleans up allocated resources.
 */
Building::~Building()
{
    delete this->state;
    state = nullptr;
}

/**
 * @brief Requests additional electricity units from the resource department.
 * @param units The amount of electricity units requested.
 * @return True if the resource department can supply the requested electricity, otherwise false.
 */
bool Building::requestElectricity(float units)
{
    cout << "Requesting electricity from Resource Department:";

    if (resourceDept->processResourceRequest("electricity", units))
    {
        electricityUnits += units;
        cout << "Resource department supplied electricity" << endl;
        if (waterUnits > 0)
        {
            delete this->state;
            this->state = new CompleteState();
        }
        return true;
    }
    cout << "Resource department could not supply electricity" << endl;
    return false;
}

/**
 * @brief Requests additional water units from the resource department.
 * @param units The amount of water units requested.
 * @return True if the resource department can supply the requested water, otherwise false.
 */
bool Building::requestWater(float units)
{
    cout << "Requesting water from Resource Department:";

    if (resourceDept->processResourceRequest("water", units))
    {
        waterUnits += units;
        cout << "Resource department supplied water" << endl;
        if (electricityUnits > 0)
        {
            delete this->state;
            this->state = new CompleteState();
        }
        return true;
    }
    cout << "Resource department could not supply water" << endl;
    return false;
}

/**
 * @brief Uses a specified amount of electricity from the building's supply if available.
 * @param units The amount of electricity units to use.
 * @return True if there is enough electricity to use and the current state allows electricity usage, otherwise false.
 */
bool Building::useElectricity(float units)
{
    if (this->electricityUnits - units < 0 || !this->state->canUseElectricity())
        return false;

    electricityUnits -= units;
    return true;
}

/**
 * @brief Uses a specified amount of water from the building's supply if available.
 * @param units The amount of water units to use.
 * @return True if there is enough water to use and the current state allows water usage, otherwise false.
 */
bool Building::useWater(float units)
{
    if (this->waterUnits - units < 0 || !this->state->canUseWater())
        return false;

    waterUnits -= units;
    return true;
}

/**
 * @brief Gets the current value of the building.
 * @return The value of the building.
 */
float Building::getValue()
{
    return this->value;
}

/**
 * @brief Gets the type of the building.
 * @return The type of the building as a string.
 */
string Building::getType()
{
    return this->type;
}

/**
 * @brief Gets the amount of water units available in the building.
 * @return The amount of water units.
 */
float Building::getWater()
{
    return waterUnits;
}

/**
 * @brief Gets the amount of electricity units available in the building.
 * @return The amount of electricity units.
 */
float Building::getElectricity()
{
    return electricityUnits;
}

/**
 * @brief Gets the cleanliness level of the building.
 * @return The cleanliness level (0 to 100).
 */
float Building::getCleanliness()
{
    return cleanliness;
}

/**
 * @brief Gets the current state of the building as a string.
 * @return The name of the current state of the building.
 */
string Building::getState()
{
    return this->state->getName();
}

/**
 * @brief Adds a reference to a ResourceDepartment object for resource management.
 * @param r Pointer to the ResourceDepartment.
 */
void Building::addResourceDept(ResourceDepartment *r)
{
    this->resourceDept = r;
}
