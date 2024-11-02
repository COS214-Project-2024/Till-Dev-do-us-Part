#include "FullCapacityServiceState.h"
#include <iostream>

void FullCapacityServiceState::handleService(ServiceUtility* utility) {
    // Logic for outage (no service)
    std::cout << utility->getName() << " is in outage state, service is unavailable." << std::endl;
    utility->setCurrentServiceLevel(0.0); // No service provided
}
