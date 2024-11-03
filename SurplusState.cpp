#include "SurplusState.h"

/**
 * @brief Checks the availability of resources and updates the state based on the current amount.
 * 
 * This method evaluates the ratio of the current amount to the initial amount and updates
 * the resource state accordingly:
 * - Changes to BalancedState if the ratio is between 50% and 99%.
 * - Changes to ShortageState if the ratio is between 25% and 49%.
 * - Changes to CriticalState if the ratio is below 25%.
 * 
 * If the current amount is 100% or more, it alerts the resource.
 * 
 * @param resource Pointer to the Resources object being checked.
 * 
 * @author Thendo
 */
void SurplusState::checkAvailability(Resources* resource)
{
    float ratio = (resource->getCurrentAmount() / resource->getInitialAmount()) * 100;

    if (ratio < 100) 
    {  
        if (ratio >= 50) 
        {
            resource->setState(new BalancedState());
        }
        else if (ratio < 50 && ratio >= 25) 
        {
            resource->setState(new ShortageState());
        }
        else 
        {
            resource->setState(new CriticalState());
        }
    }
    else 
    {
        resource->alert();
    }
}

/**
 * @brief Retrieves the status of the surplus state.
 * @return A string indicating the current state as "Surplus State".
 */
string SurplusState::getStatus()
{
    return "Surplus State";
}
