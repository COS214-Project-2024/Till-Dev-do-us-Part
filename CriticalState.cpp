#include "CriticalState.h"

/**
 * @brief Checks the availability of resources and updates the state based on the current amount.
 * 
 * This method evaluates the ratio of the current amount to the initial amount and updates
 * the resource state accordingly:
 * - Transitions to ShortageState if the ratio is between 25% and 49%.
 * - Transitions to BalancedState if the ratio is between 50% and 99%.
 * - Transitions to SurplusState if the ratio is 100% or more.
 * 
 * 
 * @author Thendo
 * 
 * @param resource Pointer to the Resources object being checked.
 */
void CriticalState::checkAvailability(Resources* resource)
{
    float ratio = (resource->getCurrentAmount() / resource->getInitialAmount()) * 100;
    
    if (ratio >= 25 && ratio < 50) 
    {
        resource->setState(new ShortageState());
    }
    else if (ratio >= 50 && ratio < 100)
    {
        resource->setState(new BalancedState());
    }
    else if (ratio >= 100)
    {
        resource->setState(new SurplusState());
    }
    else 
    {
        resource->alert(); 
    }
}

/**
 * @brief Retrieves the status of the critical state.
 * @return A string indicating the current state as "Critical State".
 */
string CriticalState::getStatus()
{
    return "Critical State";
}
