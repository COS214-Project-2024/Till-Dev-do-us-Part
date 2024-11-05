#ifndef INDUSTRIALSITE_H
#define INDUSTRIALSITE_H

#include "Industrial.h"
#include "Building.h"
#include "Plant.h"

/**
 * @brief Represents an industrial site composed of multiple industrial buildings.
 *
 * Inherits from the Industrial class and manages the loading and usage of resources
 * such as electricity and water, as well as the overall cleanliness and operations of the site.
 */
class IndustrialSite : public Industrial
{
private:
    vector<Industrial *> buildings; ///< Vector containing pointers to industrial buildings in the site.
    int noBuildings;                ///< Number of buildings currently in the industrial site.
    int cleanliness;                ///< Cleanliness rating of the industrial site.

public:
    /**
     * @brief Constructs a new IndustrialSite object with default values.
     */
    IndustrialSite();

    /**
     * @brief Destroys the IndustrialSite, cleans up resources and demolishes all buildings.
     */
    ~IndustrialSite();

    /**
     * @brief Loads a specified amount of electricity to all buildings in the industrial site.
     *
     * @param units The amount of electricity to load.
     */
    virtual void loadElectricity(float units);

    /**
     * @brief Loads a specified amount of water to all buildings in the industrial site.
     *
     * @param units The amount of water to load.
     */
    virtual void loadWater(float units);

    /**
     * @brief Uses a specified amount of electricity across all buildings.
     *
     * @param units The amount of electricity to use.
     * @return true if all buildings successfully used the electricity, false otherwise.
     */
    virtual bool useElectricity(float units);

    /**
     * @brief Uses a specified amount of water across all buildings.
     *
     * @param units The amount of water to use.
     * @return true if all buildings successfully used the water, false otherwise.
     */
    virtual bool useWater(float units);

    /**
     * @brief Gets the price of the industrial site.
     *
     * @return The value of the industrial site.
     */
    virtual float getPrice();

    /**
     * @brief Gets the type of the industrial site.
     *
     * @return The type as a string.
     */
    virtual string getType();

    /**
     * @brief Demolishes all buildings in the industrial site and frees associated resources.
     */
    virtual void demolish();

    /**
     * @brief Cleans all buildings in the industrial site using water and electricity if available.
     *
     * @return true if all buildings were successfully cleaned, false otherwise.
     */
    virtual bool clean();

    /**
     * @brief Adds a citizen to one of the buildings in the industrial site.
     *
     * @param c The citizen to add.
     * @return true if the citizen was successfully added, false otherwise.
     */
    virtual bool addOccupant(Citizen *c);

    /**
     * @brief Creates a clone of the industrial site.
     *
     * @return A pointer to the new cloned IndustrialSite object.
     */
    virtual Building *clone();

    /**
     * @brief Removes a citizen from one of the buildings in the industrial site.
     *
     * @param c The citizen to remove.
     * @return true if the citizen was successfully removed, false otherwise.
     */
    virtual bool removeOccupant(Citizen *c);

    /**
     * @brief Gets the number of buildings in the industrial site.
     *
     * @return The number of buildings.
     */
    virtual int getNoBuildings();

    /**
     * @brief Adds a building to the industrial site.
     *
     * @param building The building to add.
     * @return true if the building was successfully added, false otherwise.
     */
    virtual bool addBuilding(Industrial *building);

    /**
     * @brief Removes a building from the industrial site.
     *
     * @param building The building to remove.
     * @return true if the building was successfully removed, false otherwise.
     */
    bool removeBuilding(Industrial *building);

    /**
     * @brief Checks if the industrial site is occupied by citizens.
     *
     * @return true if all buildings are unoccupied, false otherwise.
     */
    virtual bool isOccupied();

    /**
     * @brief Gets the cleanliness of the industrial site based on the buildings.
     *
     * @return The cleanliness value.
     */
    virtual float getCleanliness();

    /**
     * @brief Gets the total water units available in the industrial site.
     *
     * @return The total water units.
     */
    virtual float getWater();

    /**
     * @brief Gets the total electricity units available in the industrial site.
     *
     * @return The total electricity units.
     */
    virtual float getElectricity();
};

#endif
