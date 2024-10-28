#include "PowerPlant.h"
#include <iostream>

PowerPlant::PowerPlant() {}
PowerPlant::PowerPlant(std::string name, ResourceDepartment *department, Resources *energy, float totalProduction, int workers)
    : Utility(name, department, energy, totalProduction, workers) {}

PowerPlant::~PowerPlant() {}

void PowerPlant::serviceDelivery()
{
    // Specific power plant logic for energy production
    std::cout << "PowerPlant " << getName() << " is generating energy." << std::endl;
    requestResource(50); // Assume the power plant requires 50 units of energy resource
}
