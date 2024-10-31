#include "WaterSupply.h"
#include <iostream>
WaterSupply::WaterSupply(std::string name, ResourceDepartment *department, Resources *resource)
    : ProductionUtility(name, department, resource)
{
    productionCapacity = 5000;
    currentProduction = 0;
    
}

WaterSupply::~WaterSupply() {}

void WaterSupply::startProduction()
{
    if (proState)
    {
        proState->handleProduction(this);
    }
}


