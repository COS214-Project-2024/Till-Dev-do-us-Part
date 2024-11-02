#include "ShortageState.h"

/**
 * @brief Checks the availability of resources and updates the state accordingly.
 * 
 * Changes the resource state based on the ratio of the current amount to the initial amount:
 * - Moves to BalancedState if the ratio is between 50% and 99%.
 * - Moves to SurplusState if the ratio is 100% or above.
 * - Moves to CriticalState if the ratio is below 25%.
 * - Alerts if none of the above conditions are met.
 * 
 * @param resource Pointer to the Resources object being checked.
 * 
 * @author Thendo
 */
void ShortageState::checkAvailability(Resources* resource)
{
    float ratio = (resource->getCurrentAmount() / resource->getInitialAmount()) * 100;

    if (ratio >= 50 && ratio < 99) {
        resource->setState(new BalancedState());
    }
    else if (ratio >= 100) {
        resource->setState(new SurplusState());
    }
    else if (ratio < 25) {
        resource->setState(new CriticalState());
    }
    else {
        resource->alert();
    }
}

/**
 * @brief Retrieves the status of the current state.
 * @return A string indicating the current state as "Shortage State".
 */
string ShortageState::getStatus()
{
    return "Shortage State";
}
