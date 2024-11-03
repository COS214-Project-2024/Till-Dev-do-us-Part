#include "OperationalServiceState.h"
#include <iostream>

/**
 * @brief Handles service operations while in the operational state.
 * 
 * Outputs a message indicating the utility is operational and processing buildings.
 * 
 * @param utility Pointer to the ServiceUtility that is operational.
 */
void OperationalServiceState::handleService(ServiceUtility *utility)
{
    std::cout << "Waste Management is operational and processing buildings." << std::endl;

    // Uncomment to implement building iteration logic
    // if (utility)
    // {
    //     utility->iterateBuildings(false, utility->getCapacity());
    // }
}

/**
 * @brief Gets the name of the operational state.
 * 
 * @return A string representing the state name.
 */
std::string OperationalServiceState::getStateName() const { return "Operational"; }
