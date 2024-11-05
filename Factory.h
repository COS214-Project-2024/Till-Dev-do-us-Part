#ifndef FACTORY_H
#define FACTORY_H

#include "Industrial.h"

/**
 * @class Factory
 * @brief Represents a factory, a type of industrial building.
 *
 * The Factory class inherits from the Industrial class and implements methods
 * for managing occupants and the state of the factory.
 */
class Factory : public Industrial
{
private:
    vector<Citizen *> occupants; /**< List of occupants in the factory. */

public:
    /**
     * @brief Constructs a Factory object.
     */
    Factory();

    /**
     * @brief Destroys the Factory object and frees resources.
     */
    ~Factory();

    /**
     * @brief Adds an occupant (Citizen) to the factory.
     *
     * @param c Pointer to the Citizen to be added.
     * @return true if the occupant was successfully added, false otherwise.
     */
    virtual bool addOccupant(Citizen *c);

    /**
     * @brief Removes an occupant (Citizen) from the factory.
     *
     * @param c Pointer to the Citizen to be removed.
     * @return true if the occupant was successfully removed, false otherwise.
     */
    virtual bool removeOccupant(Citizen *c);

    /**
     * @brief Demolishes the factory.
     */
    virtual void demolish();

    /**
     * @brief Cleans the factory.
     *
     * @return true if the factory was successfully cleaned, false otherwise.
     */
    virtual bool clean();

    /**
     * @brief Creates a clone of the factory.
     *
     * @return A pointer to a new Building object that is a clone of the current factory.
     */
    virtual Building *clone();

    /**
     * @brief Checks if the factory is occupied.
     *
     * @return true if there is at least one occupant, false otherwise.
     */
    virtual bool isOccupied();
};

#endif
