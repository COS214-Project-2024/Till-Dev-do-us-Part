#ifndef BUILDING_H
#define BUILDING_H

#include "BuildingState.h"
#include "ConstructionState.h"
#include "CompleteState.h"
#include "DilapidatedState.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class ResourceDepartment;
class Citizen;

/**
 * @class Building
 * @brief Abstract base class for various types of buildings, managing resources, state, and occupancy.
 * @author Katlego
 */
class Building
{
protected:
    BuildingState *state;             /**< Current state of the building (e.g., Complete, Dilapidated). */
    ResourceDepartment *resourceDept; /**< Pointer to the resource department for managing resources. */
    string type;                      /**< Type of the building (e.g., "House"). */
    float cleanliness;                /**< Cleanliness level of the building (0 to 100). */
    float electricityUnits;           /**< Units of electricity available in the building. */
    float waterUnits;                 /**< Units of water available in the building. */
    float value;                      /**< Value of the building. */
    float area;                       /**< Area of the building. */
    int capacity;                     /**< Maximum occupancy capacity of the building. */

public:
    /**
     * @brief Constructor for the Building class.
     * @param type The type of the building.
     */
    Building(string type);

    /**
     * @brief Virtual destructor for the Building class.
     */
    virtual ~Building();

    /**
     * @brief Requests additional electricity units if current units are insufficient.
     * @param units The amount of electricity units requested.
     * @return True if the request was successful, otherwise false.
     */
    virtual bool requestElectricity(float units);

    /**
     * @brief Requests additional water units if current units are insufficient.
     * @param units The amount of water units requested.
     * @return True if the request was successful, otherwise false.
     */
    virtual bool requestWater(float units);

    /**
     * @brief Uses a specified amount of electricity from the building's supply.
     * @param units The amount of electricity units to use.
     * @return True if there is enough electricity to use, otherwise false.
     */
    virtual bool useElectricity(float units);

    /**
     * @brief Uses a specified amount of water from the building's supply.
     * @param units The amount of water units to use.
     * @return True if there is enough water to use, otherwise false.
     */
    virtual bool useWater(float units);

    /**
     * @brief Gets the current value of the building.
     * @return The value of the building.
     */
    virtual float getValue();

    /**
     * @brief Gets the type of the building.
     * @return The type of the building as a string.
     */
    virtual string getType();

    /**
     * @brief Gets the amount of water units available in the building.
     * @return The amount of water units.
     */
    virtual float getWater();

    /**
     * @brief Gets the amount of electricity units available in the building.
     * @return The amount of electricity units.
     */
    virtual float getElectricity();

    /**
     * @brief Gets the cleanliness level of the building.
     * @return The cleanliness level.
     */
    virtual float getCleanliness();

    /**
     * @brief Demolishes the building, clearing all occupants and resources.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual void demolish() = 0;

    /**
     * @brief Cleans the building, restoring its cleanliness level.
     * @return True if cleaning was successful, otherwise false.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual bool clean() = 0;

    /**
     * @brief Adds an occupant to the building.
     * @param c Pointer to the citizen to add.
     * @return True if the occupant was added, false if the building is at full capacity.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual bool addOccupant(Citizen *c) = 0;

    /**
     * @brief Removes an occupant from the building.
     * @param c Pointer to the citizen to remove.
     * @return True if the occupant was removed, false if not found.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual bool removeOccupant(Citizen *c) = 0;

    /**
     * @brief Creates a clone of the building.
     * @return A pointer to the cloned building.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual Building *clone() = 0;

    /**
     * @brief Checks if the building has any occupants.
     * @return True if the building is occupied, otherwise false.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual bool isOccupied() = 0;

    /**
     * @brief Adds a reference to a ResourceDepartment object to manage resources.
     * @param r Pointer to the ResourceDepartment.
     */
    virtual void addResourceDept(ResourceDepartment *r);

    /**
     * @brief Gets the current state of the building.
     * @return The state of the building as a string.
     */
    virtual string getState();
};

#endif
                            