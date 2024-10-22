#include "Utility.h"
#include "OperationalState.h"
#include "MaintenanceState.h"
#include "OutageState.h"

Utility::Utility(std::string name, Resource* resource, float totalProduction, int workers)
    : name(name), resource(resource), totalProduction(totalProduction), workers(workers) {
    currentState = new OperationalState(); // Initially operational
    revenue = 0;
    currentProduction = 0;
    totalDemand = 0;
}

Utility::~Utility() {
    delete currentState; // Clean up state object
}

void Utility::startProduction() {
    currentState->startProduction(this); // Delegate production to current state
}

void Utility::setState(UtilityState* newState) {
    delete currentState; // Delete the previous state
    currentState = newState; // Assign the new state
    std::cout << name << " is now in state: " << currentState->getStateName() << std::endl;
}

float Utility::getTotalProduction() const {
    return totalProduction;
}

void Utility::setCurrentProduction(float production) {
    currentProduction = production;
}

float Utility::getCurrentProduction() const {
    return currentProduction;
}

Resource* Utility::getResource() const {
    return resource;
}

int Utility::getWorkers() const {
    return workers;
}
