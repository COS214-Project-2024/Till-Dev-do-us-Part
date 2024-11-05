#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "Residential.h"
#include "Adult.h"

/**
 * @brief The Townhouse class represents a townhouse-type residential building.
 * Inherits from the Residential class.
 * @author Katlego
 */
class Townhouse : public Residential
{
private:
    /// List of occupants residing in the townhouse.
    vector<Citizen *> occupants;

public:
    /**
     * @brief Constructor for the Townhouse class.
     * Initializes the townhouse with default properties.
     */
    Townhouse();

    /**
     * @brief Destructor for the Townhouse class.
     * Cleans up any resources used by the townhouse.
     */
    ~Townhouse();

    /**
     * @brief Demolishes the townhouse, clearing all occupants.
     */
    virtual void demolish();

    /**
     * @brief Attempts to use the shower in the townhouse.
     * @return true if the shower was used successfully, false otherwise.
     */
    virtual bool useShower();

    /**
     * @brief Attempts to use the toilet in the townhouse.
     * @return true if the toilet was used successfully, false otherwise.
     */
    virtual bool useToilet();

    /**
     * @brief Attempts to use the stove in the townhouse.
     * @return true if the stove was used successfully, false otherwise.
     */
    virtual bool useStove();

    /**
     * @brief Attempts to clean the townhouse.
     * @return true if the townhouse was cleaned successfully, false otherwise.
     */
    virtual bool clean();

    /**
     * @brief Adds a citizen to the townhouse as an occupant.
     * @param c Pointer to the Citizen to be added.
     * @return true if the occupant was added successfully, false if at capacity.
     */
    bool addOccupant(Citizen *c);

    /**
     * @brief Creates a clone of the current townhouse.
     * @return A pointer to a new cloned Townhouse object.
     */
    virtual Building *clone();

    /**
     * @brief Removes a specific occupant from the townhouse.
     * @param c Pointer to the Citizen to be removed.
     * @return true if the occupant was removed successfully, false otherwise.
     */
    bool removeOccupant(Citizen *c);

    /**
     * @brief Checks if the townhouse is currently occupied.
     * @return true if there are occupants, false otherwise.
     */
    virtual bool isOccupied();

    /**
     * @brief Displays the current state of the townhouse, including cleanliness,
     * water units, electricity units, value, area, and number of occupants.
     */
    virtual void display();
};

#endif
