#include "PowerPlant.h"
#include <iostream>

PowerPlant::PowerPlant(std::string name, ResourceDepartment* department, Resources* resource, float capacity, int workers)
    : ProductionUtility(name, department, resource, workers, capacity) {}

PowerPlant::~PowerPlant() {}

void PowerPlant::startProduction() {
    // if (currentProductionState) {
    //     currentProductionState->handleProduction(this);
    // } else {
    //     std::cout << getName() << " has no production state set.\n";
    // }
}


