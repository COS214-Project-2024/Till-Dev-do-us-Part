#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"

/**
 * @class Industrial
 * @brief Abstract class representing an industrial building.
 *
 * This class inherits from Building and provides a framework for all industrial buildings,
 * defining pure virtual functions for managing occupants and building state.
 */
class Industrial : public Building
{
public:
    /**
     * @brief Constructs an Industrial object with a specified type.
     *
     * @param type A string representing the type of the industrial building.
     */
    Industrial(string type) : Building(type) {}

    /**
     * @brief Adds an occupant (Citizen) to the industrial building.
     *
     * @param c Pointer to the Citizen to be added.
     * @return true if the occupant was successfully added, false otherwise.
     */
    virtual bool addOccupant(Citizen *c) = 0;

    /**
     * @brief Removes an occupant (Citizen) from the industrial building.
     *
     * @param c Pointer to the Citizen to be removed.
     * @return true if the occupant was successfully removed, false otherwise.
     */
    virtual bool removeOccupant(Citizen *c) = 0;

    /**
     * @brief Demolishes the industrial building.
     */
    virtual void demolish() = 0;

    /**
     * @brief Cleans the industrial building.
     *
     * @return true if the building was successfully cleaned, false otherwise.
     */
    virtual bool clean() = 0;

    /**
     * @brief Creates a clone of the industrial building.
     *
     * @return A pointer to a new Building object that is a clone of the current industrial building.
     */
    virtual Building *clone() = 0;

    /**
     * @brief Checks if the industrial building is occupied.
     *
     * @return true if there is at least one occupant, false otherwise.
     */
    virtual bool isOccupied() = 0;
};

#endif
