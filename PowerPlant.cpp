#include "PowerPlant.h"
#include <iostream>

PowerPlant::PowerPlant(std::string name, ResourceDepartment *department, Resources *resource)
    : ProductionUtility(name, department, resource)
{
    productionCapacity = 5000;
    currentProduction = 0;
    
}

PowerPlant::~PowerPlant() {}

void PowerPlant::startProduction()
{
    if (proState)
    {
        proState->handleProduction(this);
    }
}


