#include "WaterSupply.h"
#include <iostream>

WaterSupply::WaterSupply(std::string name, ResourceDepartment *department, Resources *resource, float capacity, int workers)
    : ProductionUtility(name, department, resource, workers, capacity) {}

WaterSupply::~WaterSupply() {}

void WaterSupply::startProduction()
{
    // if (currentProductionState) {
    //     currentProductionState->handleProduction(this);
    // } else {
    //     std::cout << getName() << " has no production state set.\n";
    // }
}
