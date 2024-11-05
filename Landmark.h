#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"

/**
 * @brief The Landmark class represents a type of building that can have occupants.
 *
 * This class serves as an abstract base class for different types of landmarks
 * in a simulation, allowing for various behaviors related to occupants, cleaning,
 * demolition, and cloning.
 */
class Landmark : public Building
{
protected:
    vector<Citizen *> occupants; ///< A vector holding pointers to the occupants of the landmark.

public:
    /**
     * @brief Constructs a new Landmark object with the specified type.
     *
     * @param type The type of the landmark being created.
     */
    Landmark(string type);

    /**
     * @brief Adds an occupant to the landmark.
     *
     * @param c A pointer to the Citizen to add as an occupant.
     * @return true if the occupant was successfully added, false otherwise.
     */
    virtual bool addOccupant(Citizen *c) = 0;

    /**
     * @brief Demolishes the landmark, removing it and freeing resources.
     */
    virtual void demolish() = 0;

    /**
     * @brief Cleans the landmark, resetting its cleanliness state.
     *
     * @return true if the cleaning process was successful, false otherwise.
     */
    virtual bool clean() = 0;

    /**
     * @brief Removes an occupant from the landmark.
     *
     * @param c A pointer to the Citizen to remove from occupants.
     * @return true if the occupant was successfully removed, false otherwise.
     */
    virtual bool removeOccupant(Citizen *c) = 0;

    /**
     * @brief Clones the landmark, creating a new instance with the same properties.
     *
     * @return A pointer to the cloned Building instance.
     */
    virtual Building *clone() = 0;

    /**
     * @brief Checks if the landmark is currently occupied by any citizens.
     *
     * @return true if the landmark has occupants, false otherwise.
     */
    virtual bool isOccupied();
};

#endif
