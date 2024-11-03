#ifndef SHORTAGE_STATE_H
#define SHORTAGE_STATE_H

#include "BalancedState.h"
#include "CriticalState.h"
#include "ResourceState.h"
#include "Resources.h"

/**
 * @class ShortageState
 * @brief Concrete class representing the shortage state of a resource.
 * Inherits from ResourceState and implements state-specific behavior.
 * 
 * @author Thendo
 */
class ShortageState : public ResourceState {
public:
    /**
     * @brief Checks the availability of the resource and updates its state accordingly.
     * 
     * This function evaluates the current amount of the resource relative to its initial amount
     * and changes the state of the resource based on predefined thresholds.
     * 
     * @param resource Pointer to the Resources object whose availability is being checked.
     */
    virtual void checkAvailability(Resources* resource) override;

    /**
     * @brief Retrieves the status of the shortage state.
     * @return A string indicating the current state as "Shortage State".
     */
    virtual string getStatus() override;
};

#endif // SHORTAGE_STATE_H
