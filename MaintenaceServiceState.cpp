#include "MaintenanceServiceState.h"
#include <iostream>

/**
 * @brief Handles service operations while in the maintenance state.
 * 
 * Outputs a message indicating the utility is operational and sets 
 * the current service level to full capacity.
 * 
 * @param utility Pointer to the ServiceUtility that is in maintenance.
 */
void MaintenanceServiceState::handleService(ServiceUtility* utility) {
    std::cout << utility->getName() << " is operational and providing service at full capacity." << std::endl;
    utility->setCurrentServiceLevel(utility->getServiceCap()); // Full service capacity
}
