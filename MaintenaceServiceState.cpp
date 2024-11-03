#include "MaintenanceServiceState.h"
#include <iostream>

void MaintenanceServiceState::handleService(ServiceUtility* utility) {
    // Logic for normal service operation
    std::cout << utility->getName() << " is operational and providing service at full capacity." << std::endl;
    utility->setCurrentServiceLevel(utility->getServiceCap()); // Full service capacity
}
