#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"

/**
 * @class Commercial
 * @brief Abstract base class representing a commercial building.
 *
 * This class serves as a blueprint for any type of commercial building.
 * It inherits from Building and defines pure virtual functions that
 * must be implemented by derived classes.
 */
class Commercial : public Building
{
public:
    /**
     * @brief Constructs a Commercial building with a specified type.
     * @param type The type or designation of the commercial building.
     */
    Commercial(string type);

    /**
     * @brief Demolishes the commercial building, removing it and any occupants.
     *
     * This function must be implemented by derived classes to handle
     * the demolition specifics of the building.
     */
    virtual void demolish() = 0;

    /**
     * @brief Cleans the commercial building, resetting cleanliness levels.
     * @return True if the building was successfully cleaned, otherwise false.
     */
    virtual bool clean() = 0;

    /**
     * @brief Adds an occupant to the commercial building.
     * @param c A pointer to the Citizen object representing the occupant.
     * @return True if the occupant was successfully added, false if the building is at capacity.
     */
    virtual bool addOccupant(Citizen *c) = 0;

    /**
     * @brief Removes an occupant from the commercial building.
     * @param c A pointer to the Citizen object representing the occupant to remove.
     * @return True if the occupant was successfully removed, false if the occupant was not found.
     */
    virtual bool removeOccupant(Citizen *c) = 0;

    /**
     * @brief Creates a clone of the commercial building.
     * @return A pointer to a new Building object that is a copy of the current instance.
     */
    virtual Building *clone() = 0;

    /**
     * @brief Checks if the commercial building currently has occupants.
     * @return True if there are occupants, otherwise false.
     */
    virtual bool isOccupied() = 0;
};

#endif // COMMERCIAL_H
