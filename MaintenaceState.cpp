#include "MaintenanceState.h"
#include "Utility.h"

void MaintenanceState::startProduction(Utility* utility) {
    float production = utility->getTotalProduction() * 0.5; // Half production during maintenance
    utility->setCurrentProduction(production);
    std::cout << "Utility is under maintenance. Reduced production: " << production << std::endl;
}

std::string MaintenanceState::getStateName() {
    return "Maintenance";
}
