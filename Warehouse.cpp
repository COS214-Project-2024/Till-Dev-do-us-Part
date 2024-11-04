#include "Warehouse.h"

/**
 * @brief Constructs a Warehouse object with predefined properties.
 */
Warehouse::Warehouse() : Industrial("Warehouse")
{
    area = 1000;
    capacity = 15;
    value = 30000;
    cout << "Warehouse created!" << endl;
}

/**
 * @brief Destroys the Warehouse object and frees resources.
 */
Warehouse::~Warehouse()
{
    demolish();
    cout << "Warehouse demolished!" << endl;
}

/**
 * @brief Adds an occupant (Citizen) to the warehouse.
 *
 * @param c Pointer to the Citizen to be added.
 * @return true if the occupant was successfully added, false if the warehouse is at capacity or the citizen is null.
 */
bool Warehouse::addOccupant(Citizen *c)
{
    if (c != nullptr && occupants.size() < capacity)
    {
        occupants.push_back(c);
        cout << "Occupant added" << endl;
        return true;
    }

    cout << "Could not add occupant. Building at capacity" << endl;
    return false;
}

/**
 * @brief Demolishes the warehouse and removes all occupants.
 */
void Warehouse::demolish()
{
    cout << "Removing everyone from the warehouse" << endl;
    occupants.clear();
    cout << "Everyone removed from the warehouse" << endl;
}

/**
 * @brief Cleans the warehouse using specified amounts of water and electricity.
 *
 * @return true if the warehouse was successfully cleaned, false otherwise.
 */
bool Warehouse::clean()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(500) && useElectricity(300))
        {
            cout << "Warehouse cleaned." << endl;
            return true;
        }
        cout << "Not enough water or electricity to clean the Warehouse:" << endl;
        cout << "Required water to clean: 500" << endl;
        cout << "Required electricity to clean: 300" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        if (requestElectricity(300) && requestWater(500))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    cout << "Warehouse is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

/**
 * @brief Creates a clone of the warehouse.
 *
 * @return A pointer to a new Building object that is a clone of the current warehouse.
 */
Building *Warehouse::clone()
{
    Warehouse *newWarehouse = new Warehouse();
    newWarehouse->cleanliness = this->cleanliness;
    newWarehouse->electricityUnits = this->electricityUnits;
    newWarehouse->waterUnits = this->waterUnits;
    newWarehouse->value = this->value;
    newWarehouse->area = this->area;
    newWarehouse->capacity = this->capacity;

    return newWarehouse;
}

/**
 * @brief Removes an occupant (Citizen) from the warehouse.
 *
 * @param c Pointer to the Citizen to be removed.
 * @return true if the occupant was successfully removed, false if the occupant was not found.
 */
bool Warehouse::removeOccupant(Citizen *c)
{
    vector<Citizen *>::iterator first = occupants.begin();
    vector<Citizen *>::iterator last = occupants.end();

    vector<Citizen *>::iterator it = find(first, last, c);
    if (it != last)
    {
        occupants.erase(it);
        cout << "Occupant removed from the Warehouse" << endl;
        return true;
    }

    cout << "Occupant not in the Warehouse" << endl;
    return false;
}

/**
 * @brief Checks if the warehouse is occupied.
 *
 * @return true if there are occupants in the warehouse, false otherwise.
 */
bool Warehouse::isOccupied()
{
    return occupants.size() > 0;
}
