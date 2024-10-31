#include "OutageProductionState.h"
#include <iostream>

void OutageProductionState::handleProduction(ProductionUtility* utility) {
    // Logic for outage (no production)
    std::cout << utility->getName() << " is in outage state, production is halted." << std::endl;
    utility->setCurrentProduction(0.0); // Set production to zero
}
