#include "Utility.h"
#include <iostream>

Utility::Utility() : name("Unnamed Utility"), resDept(nullptr), resource(nullptr), revenue(0.0), workers(0) {}

Utility::Utility(const std::string& name, ResourceDepartment* resDept, Resources* resource, int workers)
    : name(name), resDept(resDept), resource(resource), revenue(0.0), workers(workers) {}

Utility::~Utility() = default;

void Utility::checkForBreakdowns() {
    // Logic to check for breakdowns in utility service
    std::cout << name << " is checking for breakdowns..." << std::endl;
}

void Utility::notifyResourceDept(const std::string& message) {
    // Notify the Resource Department with a specific message
    std::cout << "Notifying Resource Department: " << message << std::endl;
}

std::string Utility::getName() const {
    return name;
}

int Utility::getWorkers() const {
    return workers;
}

std::string Utility::getStatus() const {
    return "Utility: " + name + ", Revenue: " + std::to_string(revenue) + ", Workers: " + std::to_string(workers);
}
