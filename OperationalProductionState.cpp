#include "OperationalProductionState.h"
#include <iostream>

void OperationalProductionState::startProduction(ProductionUtility* utility) {
    // Logic for normal production operation
    std::cout << utility->getName() << " is in operational state and producing resources." << std::endl;
    utility->setCurrentProduction(utility->getProductionCap()); // Set production to full capacity
}
