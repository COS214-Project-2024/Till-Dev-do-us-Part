#include "WasteManagement.h"
#include <iostream>

WasteManagement::WasteManagement(std::string name, ResourceDepartment* department, Resources* resource, int workers,float cap)
    : ServiceUtility(name, department, resource, workers,cap) {}

WasteManagement::~WasteManagement() {}

void WasteManagement::startService() {
    // if (currentServiceState) {
    //     currentServiceState->handleService(this);
    // } else {
    //     std::cout << getName() << " has no service state set.\n";
    // }
}

