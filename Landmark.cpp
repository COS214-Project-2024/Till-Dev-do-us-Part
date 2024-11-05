#include "Landmark.h"

/**
 * @brief Constructs a new Landmark object with the specified type.
 *
 * @param type The type of the landmark being created.
 */
Landmark::Landmark(string type) : Building(type)
{
}

/**
 * @brief Demolishes the landmark, removing all occupants.
 *
 * This method clears the occupants vector, effectively removing all citizens
 * from the landmark and preparing it for destruction.
 */
void Landmark::demolish()
{
    cout << "Removing everyone from the " << this->type << endl;
    occupants.clear();
}

/**
 * @brief Adds an occupant to the landmark.
 *
 * @param c A pointer to the Citizen to add as an occupant.
 * @return true if the occupant was successfully added, false if the landmark
 * is at capacity or if the citizen is null.
 */
bool Landmark::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        if (occupants.size() < capacity)
        {
            occupants.push_back(c);
            cout << "Citizen added to " << this->type << endl;
            return true;
        }
        cout << "Citizen " << c << " could not be added to " << this->type
             << ". " << this->type << " is at capacity." << endl;
        return false;
    }

    cout << "Citizen is non-existent." << endl;
    return false;
}

/**
 * @brief Checks if the landmark is currently occupied by any citizens.
 *
 * @return true if the landmark has one or more occupants, false otherwise.
 */
bool Landmark::isOccupied()
{
    return occupants.size() > 0;
}
