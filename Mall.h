/**
 *@file Mall.h
 *@brief Declaration of the Mall class, representing a commercial mall containing multiple buildings. 
*/
#ifndef MALL_H
#define MALL_H

#include "Commercial.h"
#include <vector>

class Citizen;

/**
 * @class Mall
 * @brief Represents a Mall containing multiple commercial buildings.
 */
class Mall : public Commercial
{
    private:
        std::vector<Commercial *> stores; /**< Vector of pointers to stores within the Mall */
        std::vector<Citizen *> owners;    /**< Vector of pointers to owners of the stores */
        int noBuildings;                  /**< Number of buildings currently in the Mall */

    public:
        /**
         * @brief Constructs a Mall object with default values.
         */
        Mall();

        /**
         * @brief Destroys the Mall object, demolishing all stores within.
         */
        ~Mall();

        /**
         * @brief Adds a building to the Mall.
         * @param building Pointer to a Commercial building to add.
         * @return true if the building was successfully added, false if capacity is reached.
         */
        bool addBuilding(Commercial *building);

        /**
         * @brief Removes a specified building from the Mall.
         * @param building Pointer to the Commercial building to remove.
         * @return true if the building was successfully removed, false otherwise.
         */
        bool removeBuilding(Commercial *building);

        /**
         * @brief Demolishes the Mall, removing all stores and occupants.
         */
        virtual void demolish();

        /**
         * @brief Cleans the Mall if resources are available.
         * @return true if cleaning was successful, false otherwise.
         */
        virtual bool clean();

        /**
         * @brief Adds an occupant to the Mall.
         * @param c Pointer to the Citizen to be added as an occupant.
         * @return true if the occupant was successfully added, false if at capacity.
         */
        virtual bool addOccupant(Citizen *c);

        /**
         * @brief Removes the specified occupant from the Mall.
         * @param c Pointer to the Citizen to be removed.
         * @return true if the occupant was successfully removed, false otherwise.
         */
        virtual bool removeOccupant(Citizen *c);

        /**
         * @brief Creates a clone of the Mall object.
         * @return A pointer to a new Building object that is a clone of the Mall.
         */
        virtual Building *clone();

        /**
         * @brief Gets the current number of buildings in the Mall.
         * @return The number of buildings in the Mall.
         */
        int getNoBuildings();

        /**
         * @brief Retrieves the cleanliness level of the Mall.
         * @return The current cleanliness level.
         */
        virtual float getCleanliness();

        /**
         * @brief Retrieves the current water usage of the Mall.
         * @return The current water usage in units.
         */
        virtual float getWater();

        /**
         * @brief Retrieves the current electricity usage of the Mall.
         * @return The current electricity usage in units.
         */
        virtual float getElectricity();

        /**
         * @brief Checks if the Mall currently has any occupants.
         * @return true if the Mall has occupants, false otherwise.
         */
        virtual bool isOccupied();
};

#endif
