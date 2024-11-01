/**
 * @file LifeStage.h
 * @brief Defines the LifeStage class, representing various life stages of an Adult Citizen.
 * @author Karabo
 */

#ifndef LIFESTAGE_H
#define LIFESTAGE_H

#include "Adult.h"

/**
 * @class LifeStage
 * @brief A class that represents a life stage of an Adult Citizen.
 * 
 * Inherits from the Adult class and provides methods to manage net worth and child status.
 */
class LifeStage : public Adult {
protected:
    Citizen* person; /**< Pointer to the Citizen object representing the person in this life stage. */

public:
    /**
     * @brief Increases the net worth of the Adult by a specified value.
     * 
     * @param value The amount to add to the net worth.
     */
    virtual void increaseNW(float value) {
        netWorth += value; // Increases net worth by the given value.
    }

    /**
     * @brief Checks if the Adult Citizen has a child.
     * 
     * @return bool Always returns false, indicating that this life stage does not have a child.
     */
    virtual bool hasChild() {
        return false; // Default implementation indicating no children.
    }

    /**
     * @brief Virtual destructor for the LifeStage class.
     * 
     * Allows for proper cleanup of derived classes when a pointer to LifeStage is deleted.
     */
    virtual ~LifeStage() {}
};

#endif // LIFESTAGE_H
