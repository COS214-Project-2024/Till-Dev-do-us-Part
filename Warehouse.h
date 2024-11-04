#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Industrial.h"

/**
 * @brief The Warehouse class represents an industrial building that can hold multiple occupants.
 *
 * Inherits from the Industrial class and implements methods to manage occupants,
 * perform cleaning, and handle demolition of the warehouse.
 */
class Warehouse : public Industrial
{
private:
    vector<Citizen *> occupants; /**< List of occupants in the warehouse. */

public:
    /**
     * @brief Constructs a Warehouse object with predefined properties.
     */
    Warehouse();

    /**
     * @brief Destroys the Warehouse object and frees resources.
     */
    virtual ~Warehouse();

    /**
     * @brief Adds an occupant (Citizen) to the warehouse.
     *
     * @param c Pointer to the Citizen to be added.
     * @return true if the occupant was successfully added, false if the warehouse is at capacity or the citizen is null.
     */
    virtual bool addOccupant(Citizen *c);

    /**
     * @brief Removes an occupant (Citizen) from the warehouse.
     *
     * @param c Pointer to the Citizen to be removed.
     * @return true if the occupant was successfully removed, false if the occupant was not found.
     */
    virtual bool removeOccupant(Citizen *c);

    /**
     * @brief Demolishes the warehouse and removes all occupants.
     */
    virtual void demolish();

    /**
     * @brief Cleans the warehouse using specified amounts of water and electricity.
     *
     * @return true if the warehouse was successfully cleaned, false otherwise.
     */
    virtual bool clean();

    /**
     * @brief Creates a clone of the warehouse.
     *
     * @return A pointer to a new Building object that is a clone of the current warehouse.
     */
    virtual Building *clone();

    /**
     * @brief Checks if the warehouse is occupied.
     *
     * @return true if there are occupants in the warehouse, false otherwise.
     */
    virtual bool isOccupied();
};

#endif
