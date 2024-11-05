#include "Office.h"

/**
 * @file Office.cpp
 * @brief Implementation of the Office class, representing an office space within a commercial building.
 */

/**
 * @brief Constructs an Office object with default values.
 */
Office::Office() : Commercial("Office")
{
    area = 800;
    value = 12000;
    capacity = 1;
    occupant = nullptr;
}

/**
 * @brief Destroys the Office object, demolishing the office and removing the occupant.
 */
Office::~Office()
{
    demolish();
    cout << "Office demolished!" << endl;
}

/**
 * @brief Demolishes the Office, removing any occupant present.
 */
void Office::demolish()
{
    cout << "Removing occupant from the Office" << endl;
    occupant = nullptr;
}

/**
 * @brief Cleans the Office if enough water and electricity are available.
 *
 * @return true if the cleaning was successful, false otherwise.
 */
bool Office::clean()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(150) && useElectricity(40))
        {
            cout << "Office cleaned.\n";
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
                    cout << "Office is now in Operational state" << endl;
                    cout << "Cleanliness: " << cleanliness << "\n";
                    cout << "Electricity: " << electricityUnits << "\n";
                    cout << "Water: " << waterUnits << "\n";
                }
                cleanliness += 30;
            }
            return true;
        }
        cout << "Not enough water or electricity to clean the Office:" << endl;
        cout << "Required water to clean: 150" << endl;
        cout << "Required electricity to clean: 40" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        if (requestElectricity(40) && requestWater(150))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    cout << "Office is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

/**
 * @brief Adds an occupant to the Office.
 *
 * @param c Pointer to the Citizen to be added as an occupant.
 * @return true if the occupant was successfully added, false if the office already has an occupant.
 */
bool Office::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        if (occupant == nullptr)
        {
            occupant = c;
            cout << "Occupant added to the Office!" << endl;
            return true;
        }
        else
        {
            cout << "The Office already has an occupant." << endl;
            return false;
        }
    }

    cout << "Cannot add a non-existent citizen to Office" << endl;
    return false;
}

/**
 * @brief Removes the specified occupant from the Office.
 *
 * @param c Pointer to the Citizen to be removed.
 * @return true if the occupant was successfully removed, false otherwise.
 */
bool Office::removeOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        if (occupant == nullptr)
        {
            cout << "Office has no occupant" << endl;
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

    cout << "Cannot remove a non-existent citizen from Office" << endl;
    return false;
}

/**
 * @brief Creates a clone of the Office object.
 *
 * @return A pointer to a new Building object that is a clone of the Office.
 */
Building *Office::clone()
{
    Office *newBuilding = new Office();
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
 * @brief Checks if the Office currently has an occupant.
 *
 * @return true if the Office has an occupant, false otherwise.
 */
bool Office::isOccupied()
{
    return occupant != nullptr;
}
