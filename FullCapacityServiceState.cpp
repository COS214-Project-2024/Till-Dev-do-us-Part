#include "FullCapacityServiceState.h"
#include <iostream>

/**
 * @brief Handles service requests in the full capacity state.
 * 
 * This method prints the service's current state and sets the current service level to zero,
 * indicating no service is available.
 * 
 * @param utility Pointer to the ServiceUtility managing the service.
 */
void FullCapacityServiceState::handleService(ServiceUtility* utility) {
    std::cout << utility->getName() << " is in full capacity state, service is unavailable." << std::endl;
    utility->setCurrentServiceLevel(0.0f); // No service provided
}
