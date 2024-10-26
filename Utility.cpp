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
    checkForBreakdowns(); // Check for random breakdowns before starting production
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

void Utility::requestResource(float amount) {
    if (resourceManager->hasSufficientResource(resource, amount)) {
        resourceManager->consumeResource(resource, amount);
        currentProduction += amount;
    } else {
        notifyResourceDivision("Insufficient resources for " + name);
        setState(new OutageState());
    }
}

// Randomly check for breakdowns and switch to MaintenanceState
void Utility::checkForBreakdowns() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    int randomValue = dis(gen);
    if (randomValue <= 10) { // 10% chance of breakdown
        std::cout << name << " is experiencing a breakdown!" << std::endl;
        setState(new MaintenanceState());
    }
}

// Notify ResourceDivision if there are issues
void Utility::notifyResourceDivision(const std::string& message) {
    std::cout << "Notification to ResourceDivision: " << message << std::endl;
}
