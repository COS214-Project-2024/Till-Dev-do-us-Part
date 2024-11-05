#ifndef SHOP_H
#define SHOP_H
#include "Commercial.h"

/**
 * @class Shop
 * @brief Represents a shop as a type of commercial building.
 *
 * This class inherits from the Commercial class and defines specific behaviors
 * for a shop, including occupancy and cleanliness management.
 */
class Shop : public Commercial
{
private:
    /**
     * @brief The current occupant of the shop.
     *
     * This pointer refers to a single Citizen who occupies the shop.
     * The shop can have only one occupant at a time.
     */
    Citizen *occupant;

public:
    /**
     * @brief Constructs a Shop object.
     *
     * Initializes the shop with default settings and values.
     */
    Shop();

    /**
     * @brief Destroys the Shop object.
     *
     * Cleans up resources used by the shop, including removing any occupant.
     */
    ~Shop();

    /**
     * @brief Demolishes the shop.
     *
     * Clears the shop of any occupant and marks it as demolished.
     */
    virtual void demolish();

    /**
     * @brief Cleans the shop.
     *
     * Ensures the shop meets cleanliness requirements.
     * @return True if the shop was successfully cleaned, false otherwise.
     */
    virtual bool clean();

    /**
     * @brief Adds an occupant to the shop.
     *
     * Assigns a Citizen to occupy the shop, if it is currently unoccupied.
     * @param c Pointer to the Citizen to be added as the occupant.
     * @return True if the occupant was successfully added, false if already occupied.
     */
    virtual bool addOccupant(Citizen *c);

    /**
     * @brief Removes the occupant from the shop.
     *
     * Releases the current occupant of the shop.
     * @param c Pointer to the Citizen to be removed.
     * @return True if the occupant was successfully removed, false if not found.
     */
    virtual bool removeOccupant(Citizen *c);

    /**
     * @brief Creates a clone of the Shop.
     *
     * Generates a new Shop object with the same properties as the original.
     * @return Pointer to the new Shop object.
     */
    virtual Building *clone();

    /**
     * @brief Checks if the shop is occupied.
     *
     * Determines whether there is currently an occupant in the shop.
     * @return True if the shop has an occupant, false otherwise.
     */
    virtual bool isOccupied();
};

#endif
