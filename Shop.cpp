/**
 *@file Shop.h
 *@brief This file contains the implementation of the Shop class, which inherits from the Commercial class. 
*/
#include "Shop.h"

/**
 * @brief Constructs a new Shop object with default values for area, value, and capacity.
 */
Shop::Shop() : Commercial("Shop")
{
    area = 200;
    value = 180000;
    capacity = 1;
    occupant = nullptr;
}

/**
 * @brief Destroys the Shop object and demolishes it, removing its occupant if present.
 */
Shop::~Shop()
{
    demolish();
    cout << "Shop demolished!" << endl;
}

/**
 * @brief Demolishes the shop by setting the occupant to nullptr.
 */
void Shop::demolish()
{
    cout << "Removing occupant from the Shop" << endl;
    occupant = nullptr;
}

/**
 * @brief Cleans the shop if there are sufficient water and electricity resources.
 * @return true if the shop is successfully cleaned, false otherwise.
 */
bool Shop::clean()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(350) && useElectricity(300))
        {
            cout << "Shop cleaned.";
            if (cleanliness - 10 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
                cout << "Shop is now in Dilapidated state:\n";
                cout << "Cleanliness: " << cleanliness << "\n";
                cout << "Electricity: " << electricityUnits << "\n";
                cout << "Water: " << waterUnits << "\n";
            }
            else
            {
                cleanliness -= 10;
            }
            return true;
        }
        cout << "Not enough water or electricity to clean the Shop:" << endl;
        cout << "Required water to clean: 350" << endl;
        cout << "Required electricity to clean: 300" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;

        if (requestElectricity(300) && requestWater(350))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    cout << "Shop is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

/**
 * @brief Adds an occupant to the shop if it is currently unoccupied.
 * @param c Pointer to the Citizen to be added as an occupant.
 * @return true if the occupant was successfully added, false if the shop already has an occupant.
 */
bool Shop::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        if (occupant == nullptr)
        {
            occupant = c;
            cout << "Occupant added to the Shop!" << endl;
            return true;
        }
        else
        {
            cout << "The Shop already has an occupant." << endl;
            return false;
        }
    }

    cout << "Cannot add a non-existent citizen to Shop" << endl;
    return false;
}

/**
 * @brief Removes the specified occupant from the shop if they are present.
 * @param c Pointer to the Citizen to be removed.
 * @return true if the occupant was successfully removed, false otherwise.
 */
bool Shop::removeOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        if (occupant == nullptr)
        {
            cout << "Shop has no occupant" << endl;
            return true;
        }
        else
        {
            if (occupant == c)
            {
                occupant = nullptr;
                cout << "Occupant removed!" << endl;
                return true;
            }
            else
            {
                cout << "Occupant not found." << endl;
                return false;
            }
        }
    }

    cout << "Cannot remove a non-existent citizen from Shop" << endl;
    return false;
}

/**
 * @brief Creates a clone of the Shop object, including its current state and attributes.
 * @return A pointer to a new Building object that is a clone of the shop.
 */
Building *Shop::clone()
{
    Shop *newBuilding = new Shop();
    newBuilding->state = this->state->clone();
    newBuilding->cleanliness = this->cleanliness;
    newBuilding->electricityUnits = this->electricityUnits;
    newBuilding->waterUnits = this->waterUnits;
    newBuilding->value = this->value;
    newBuilding->area = this->area;
    newBuilding->capacity = this->capacity;

    return newBuilding;
}

/**
 * @brief Checks if the shop currently has an occupant.
 * @return true if the shop has an occupant, false otherwise.
 */
bool Shop::isOccupied()
{
    return occupant != nullptr;
}
