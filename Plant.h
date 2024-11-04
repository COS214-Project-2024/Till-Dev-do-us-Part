#ifndef PLANT_H
#define PLANT_H
#include "Industrial.h"

/**
 * @brief Represents a Plant, which is a type of Industrial building that can contain multiple other industrial buildings.
 */
class Plant : public Industrial
{
private:
    vector<Industrial *> buildings; ///< Stores a list of buildings within the plant.
    int noBuildings;                ///< Keeps track of the number of buildings in the plant.

public:
    /**
     * @brief Constructs a Plant object with predefined properties.
     */
    Plant();

    /**
     * @brief Destroys the Plant object and frees resources.
     */
    ~Plant();

    /**
     * @brief Demolishes all buildings within the plant.
     */
    virtual void demolish();

    /**
     * @brief Cleans the plant and all its buildings.
     *
     * @return true if the plant was successfully cleaned, false otherwise.
     */
    virtual bool clean();

    /**
     * @brief Adds an occupant (Citizen) to the plant.
     *
     * @param c Pointer to the Citizen to be added.
     * @return true if the occupant was successfully added, false otherwise.
     */
    virtual bool addOccupant(Citizen *c);

    /**
     * @brief Removes an occupant (Citizen) from the plant.
     *
     * @param c Pointer to the Citizen to be removed.
     * @return true if the occupant was successfully removed, false otherwise.
     */
    virtual bool removeOccupant(Citizen *c);

    /**
     * @brief Adds a building to the plant.
     *
     * @param building Pointer to the Industrial building to be added.
     * @return true if the building was successfully added, false if the plant is at capacity.
     */
    virtual bool addBuilding(Industrial *);

    /**
     * @brief Removes a building from the plant.
     *
     * @param building Pointer to the Industrial building to be removed.
     * @return true if the building was successfully removed, false if the building was not found.
     */
    virtual bool removeBuilding(Industrial *);

    /**
     * @brief Creates a clone of the plant.
     *
     * @return A pointer to a new Building object that is a clone of the current plant.
     */
    virtual Building *clone();

    /**
     * @brief Calculates and returns the cleanliness of the plant.
     *
     * @return The cleanliness value of the plant.
     */
    virtual float getCleanliness();

    /**
     * @brief Calculates and returns the total water available in the plant.
     *
     * @return The total amount of water units in the plant.
     */
    virtual float getWater();

    /**
     * @brief Calculates and returns the total electricity available in the plant.
     *
     * @return The total amount of electricity units in the plant.
     */
    virtual float getElectricity();

    /**
     * @brief Checks if the plant is occupied by any occupants.
     *
     * @return true if there are occupants in the plant, false otherwise.
     */
    virtual bool isOccupied();

    /**
     * @brief Gets the number of buildings in the plant.
     *
     * @return The count of buildings within the plant.
     */
    virtual int getNoBuildings();
};
#endif
