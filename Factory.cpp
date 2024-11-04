#include "Factory.h"

/**
 * @brief Constructs a Factory object with predefined area, capacity, and value.
 */
Factory::Factory() : Industrial("Factory")
{
    area = 1300;   /**< Area of the factory in square units. */
    capacity = 15; /**< Maximum number of occupants allowed in the factory. */
    value = 50000; /**< Monetary value of the factory. */
    cout << "Factory created" << endl;
}

/**
 * @brief Destroys the Factory object and frees resources.
 */
Factory::~Factory()
{
    demolish();
    cout << "Factory demolished!" << endl;
}

/**
 * @brief Adds an occupant (Citizen) to the factory.
 *
 * @param c Pointer to the Citizen to be added.
 * @return true if the occupant was successfully added, false if the factory is at capacity or the citizen is null.
 */
bool Factory::addOccupant(Citizen *c)
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
 * @brief Demolishes the factory and removes all occupants.
 */
void Factory::demolish()
{
    cout << "Removing everyone from the Factory" << endl;
    occupants.clear(); // Clear the occupants list
}

/**
 * @brief Cleans the factory using specified amounts of water and electricity.
 *
 * @return true if the factory was successfully cleaned, false otherwise.
 */
bool Factory::clean()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(1200) && useElectricity(700))
        {
            cout << "Factory cleaned." << endl;
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

/**
 * @brief Creates a clone of the factory.
 *
 * @return A pointer to a new Building object that is a clone of the current factory.
 */
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

/**
 * @brief Removes an occupant (Citizen) from the factory.
 *
 * @param c Pointer to the Citizen to be removed.
 * @return true if the occupant was successfully removed, false if the occupant was not found.
 */
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

/**
 * @brief Checks if the factory is occupied.
 *
 * @return true if there are occupants in the factory, false otherwise.
 */
bool Factory::isOccupied()
{
    return occupants.size() > 0;
}
