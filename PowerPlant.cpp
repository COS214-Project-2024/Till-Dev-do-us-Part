#include "PowerPlant.h"
#include <iostream>

PowerPlant::PowerPlant(std::string name, Resource* resource, float totalProduction, int workers)
    : Utility(name, resource, totalProduction, workers) {}

PowerPlant::~PowerPlant() {}

void PowerPlant::serviceDelivery() {
    // Specific power plant logic for energy production
    std::cout << "PowerPlant " << name << " is generating energy." << std::endl;
    requestResource(50); // Assume the power plant requires 50 units of energy resource
}
