#ifndef HOUSE_H
#define HOUSE_H
#include "Residential.h"

/**
 * @class House
 * @brief A concrete residential building that represents a house with various facilities.
 *
 * The House class provides implementations for specific residential functionalities, including
 * managing occupants, using amenities like shower, toilet, and stove, and maintaining cleanliness.
 * @author Katlego
 */
class House : public Residential
{
private:
    /**
     * @brief List of occupants currently living in the house.
     */
    vector<Citizen *> occupants;

public:
    /**
     * @brief Constructs a House object with default settings.
     */
    House();

    /**
     * @brief Destructor for the House class. Ensures proper cleanup of resources.
     */
    ~House();

    /**
     * @brief Demolishes the house by clearing all occupants and resetting the building's state.
     */
    virtual void demolish();

    /**
     * @brief Allows an occupant to use the shower, consuming water and electricity.
     * @return True if the shower was successfully used, otherwise false.
     */
    virtual bool useShower();

    /**
     * @brief Allows an occupant to use the toilet, consuming water and electricity.
     * @return True if the toilet was successfully used, otherwise false.
     */
    virtual bool useToilet();

    /**
     * @brief Allows an occupant to use the stove, consuming electricity.
     * @return True if the stove was successfully used, otherwise false.
     */
    virtual bool useStove();

    /**
     * @brief Cleans the house, restoring its cleanliness level.
     * @return True if the cleaning operation was successful, otherwise false.
     */
    virtual bool clean();

    /**
     * @brief Adds an occupant to the house if there is capacity.
     * @param c Pointer to the Citizen to add as an occupant.
     * @return True if the occupant was successfully added, otherwise false.
     */
    virtual bool addOccupant(Citizen *c);

    /**
     * @brief Creates a clone of the house with the current state.
     * @return A pointer to the cloned House object.
     */
    Building *clone();

    /**
     * @brief Removes a specified occupant from the house.
     * @param c Pointer to the Citizen to remove from the house.
     * @return True if the occupant was successfully removed, otherwise false.
     */
    bool removeOccupant(Citizen *c);

    /**
     * @brief Checks if the house has any occupants.
     * @return True if the house is occupied, otherwise false.
     */
    virtual bool isOccupied();

    /**
     * @brief Displays the current state and details of the house.
     */
    virtual void display();
};

#endif
