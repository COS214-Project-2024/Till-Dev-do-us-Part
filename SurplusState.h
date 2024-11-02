#ifndef SURPLUS_STATE_H
#define SURPLUS_STATE_H

#include "BalancedState.h"
#include "ResourceState.h"
#include "Resources.h"

/**
 * @class SurplusState
 * @brief Concrete class representing the surplus state of a resource.
 * Inherits from ResourceState and implements state-specific behavior.
 * 
 * @author Thendo
 */
class SurplusState : public ResourceState {
public:
    /**
     * @brief Checks the availability of resources and updates the state based on the current amount.
     * 
     * This method evaluates the ratio of the current amount to the initial amount and updates
     * the resource state accordingly, transitioning to:
     * - BalancedState if the ratio is between 50% and 99%.
     * - ShortageState if the ratio is between 25% and 49%.
     * - CriticalState if the ratio is below 25%.
     * 
     * @param resource Pointer to the Resources object being checked.
     */
    void checkAvailability(Resources* resource) override;

    /**
     * @brief Retrieves the status of the surplus state.
     * @return A string indicating the current state as "Surplus State".
     */
    string getStatus() override;
};

#endif // SURPLUS_STATE_H
