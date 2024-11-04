#ifndef CBD_H
#define CBD_H

#include "Commercial.h"
#include "Mall.h"

class CBD : public Commercial
{
private:
    vector<Building *> buildings; ///< Collection of buildings in the CBD.
    int noBuildings;              ///< Number of buildings currently in the CBD.
    int cleanliness;              ///< Cleanliness level of the CBD.

public:
    /**
     * @brief Default constructor for the CBD class.
     */
    CBD();

    /**
     * @brief Destructor for the CBD class.
     */
    ~CBD();

    /**
     * @brief Loads a specified amount of electricity into the CBD.
     *
     * @param units The amount of electricity to load.
     */
    virtual void loadElectricity(float units);

    /**
     * @brief Loads a specified amount of water into the CBD.
     *
     * @param units The amount of water to load.
     */
    virtual void loadWater(float units);

    /**
     * @brief Uses a specified amount of electricity from the CBD.
     *
     * @param units The amount of electricity to use.
     * @return true if the electricity usage was successful, false otherwise.
     */
    virtual bool useElectricity(float units);

    /**
     * @brief Uses a specified amount of water from the CBD.
     *
     * @param units The amount of water to use.
     * @return true if the water usage was successful, false otherwise.
     */
    virtual bool useWater(float units);

    /**
     * @brief Calculates and returns the price of the CBD.
     *
     * @return The price of the CBD.
     */
    virtual float getPrice();

    /**
     * @brief Returns the type of building (CBD).
     *
     * @return A string representing the type of building.
     */
    virtual string getType();

    /**
     * @brief Demolishes all buildings in the CBD.
     */
    virtual void demolish();

    /**
     * @brief Cleans the CBD.
     *
     * @return true if the cleaning was successful, false otherwise.
     */
    virtual bool clean();

    /**
     * @brief Adds a citizen as an occupant in the CBD.
     *
     * @param c A pointer to the Citizen to be added.
     * @return true if the occupant was successfully added, false otherwise.
     */
    virtual bool addOccupant(Citizen *c);

    /**
     * @brief Creates a clone of the CBD.
     *
     * @return A pointer to the newly created CBD object.
     */
    virtual Building *clone();

    /**
     * @brief Removes a citizen from the CBD.
     *
     * @param c A pointer to the Citizen to be removed.
     * @return true if the occupant was successfully removed, false if not found.
     */
    virtual bool removeOccupant(Citizen *c);

    /**
     * @brief Returns the number of buildings in the CBD.
     *
     * @return The number of buildings.
     */
    virtual int getNoBuildings();

    /**
     * @brief Adds a building to the CBD.
     *
     * @param building A pointer to the Building to be added.
     * @return true if the building was successfully added, false otherwise.
     */
    virtual bool addBuilding(Building *building);

    /**
     * @brief Removes a building from the CBD.
     *
     * @param building A pointer to the Building to be removed.
     * @return true if the building was successfully removed, false if not found.
     */
    virtual bool removeBuilding(Building *);

    /**
     * @brief Checks if the CBD is occupied.
     *
     * @return true if the CBD is occupied, false otherwise.
     */
    virtual bool isOccupied();

    /**
     * @brief Returns the cleanliness level of the CBD.
     *
     * @return The cleanliness level.
     */
    virtual float getCleanliness();

    /**
     * @brief Returns the total amount of water in the CBD.
     *
     * @return The total amount of water.
     */
    virtual float getWater();

    /**
     * @brief Returns the total amount of electricity in the CBD.
     *
     * @return The total amount of electricity.
     */
    virtual float getElectricity();
};

#endif
