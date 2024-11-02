#include "BalancedState.h"

/**
 * @brief Checks the availability of resources and updates the state based on the current amount.
 * 
 * This method evaluates the ratio of the current amount to the initial amount and updates
 * the resource state accordingly:
 * - Transitions to SurplusState if the ratio is 100% or more.
 * - Transitions to ShortageState if the ratio is between 25% and 49%.
 * - Transitions to CriticalState if the ratio is below 25%.
 * 
 * 
 * @author Thendo
 * 
 * @param resource Pointer to the Resources object being checked.
 */
void BalancedState::checkAvailability(Resources* resource)
{
    float ratio = (resource->getCurrentAmount() / resource->getInitialAmount()) * 100;
    
    if (ratio >= 100) {
        resource->setState(new SurplusState());
    }
    else if (ratio < 50 && ratio >= 25) {
        resource->setState(new ShortageState());
    }
    else if (ratio < 25) {
        resource->setState(new CriticalState());
    }
    else {
        resource->alert();  
    }
}

/**
 * @brief Retrieves the status of the balanced state.
 * @return A string indicating the current state as "Balanced State".
 */
string BalancedState::getStatus()
{
    return "Balanced State";
}
