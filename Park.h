#ifndef PARK_H
#define PARK_H

#include "Landmark.h"

class Citizen; // Forward declaration of the Citizen class

/**
 * @brief The Park class represents a park that can have occupants and can be cleaned or demolished.
 */
class Park : public Landmark
{
public:
    /**
     * @brief Default constructor for the Park class.
     * Initializes a new instance of the Park.
     */
    Park();

    /**
     * @brief Destructor for the Park class.
     * Cleans up any resources used by the Park.
     */
    ~Park();

    /**
     * @brief Adds a citizen to the park as an occupant.
     *
     * @param c A pointer to the Citizen to be added.
     * @return true if the citizen was successfully added, false otherwise.
     */
    virtual bool addOccupant(Citizen *c);

    /**
     * @brief Demolishes the park, removing all resources.
     */
    virtual void demolish();

    /**
     * @brief Cleans the park.
     *
     * @return true if the park was successfully cleaned, false otherwise.
     */
    virtual bool clean();

    /**
     * @brief Removes a citizen from the park.
     *
     * @param c A pointer to the Citizen to be removed.
     * @return true if the citizen was successfully removed, false otherwise.
     */
    virtual bool removeOccupant(Citizen *c);

    /**
     * @brief Clones the park, creating a deep copy of it.
     *
     * @return A pointer to the cloned Park object.
     */
    virtual Building *clone();
};

#endif // PARK_H
