#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H
#include "Building.h"

class Citizen;

/**
 * @class Residential
 * @brief Abstract base class for residential buildings that inherit from Building.
 *
 * This class provides additional functionalities specific to residential buildings,
 * such as managing occupants and handling specific residential facilities (e.g., shower, toilet, stove).
 * @author Katlego
 */
class Residential : public Building
{
public:
    /**
     * @brief Constructs a Residential building of the specified type.
     * @param type The type of the residential building (e.g., "House").
     */
    Residential(string type) : Building(type) {}

    /**
     * @brief Adds an occupant to the residential building.
     * @param c Pointer to the Citizen to add as an occupant.
     * @return True if the occupant was successfully added, otherwise false.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual bool addOccupant(Citizen *c) = 0;

    /**
     * @brief Demolishes the residential building, clearing all occupants and resources.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual void demolish() = 0;

    /**
     * @brief Cleans the residential building, restoring its cleanliness level.
     * @return True if cleaning was successful, otherwise false.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual bool clean() = 0;

    /**
     * @brief Allows an occupant to use the shower in the building.
     * @return True if the shower was successfully used, otherwise false.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual bool useShower() = 0;

    /**
     * @brief Allows an occupant to use the toilet in the building.
     * @return True if the toilet was successfully used, otherwise false.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual bool useToilet() = 0;

    /**
     * @brief Allows an occupant to use the stove in the building.
     * @return True if the stove was successfully used, otherwise false.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual bool useStove() = 0;

    /**
     * @brief Creates a clone of the residential building.
     * @return A pointer to the cloned residential building.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual Building *clone() = 0;

    /**
     * @brief Checks if the residential building has any occupants.
     * @return True if the building is occupied, otherwise false.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual bool isOccupied() = 0;
};

#endif
