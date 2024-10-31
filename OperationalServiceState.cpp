#include "OperationalServiceState.h"
#include <iostream>

void OperationalServiceState::handleService(ServiceUtility* utility) {
    // Logic for normal service operation
    std::cout << utility->getName() << " is operational and providing service at full capacity." << std::endl;
    utility->setCurrentServiceLevel(utility->getServiceCap()); // Full service capacity
}

   std::string OperationalServiceState::getStateName() const  { return "Operational"; }
