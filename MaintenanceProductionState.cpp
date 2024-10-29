#include "MaintenanceProductionState.h"
#include <iostream>

void MaintenanceProductionState::startProduction(ProductionUtility* utility) {
    // Logic for maintenance mode (reduced or zero production)
    std::cout << utility->getName() << " is under maintenance, production is reduced." << std::endl;
    utility->setCurrentProduction(utility->getProductionCap() * 0.5); // Set production to half capacity
}
