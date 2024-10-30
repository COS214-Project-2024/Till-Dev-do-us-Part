#include "Road.h"
#include "EmptyState.h"
#include "NormalState.h"
#include "CongestedState.h"
#include "TransState.h"

#include <iostream>
#include <algorithm>
#include <string>

Road:: Road(){
    std::cout << "Building Road." << std::endl;
    
}

Road::Road(TransState* state) : TransportFacilities(state) {}

Road::~Road() {
    delete currentState;
}

void Road::addVehicle(TransportMode* vehicle) {
    vehicles.push_back(vehicle);
    changeState();  // Reevaluate state whenever a vehicle is added
}

void Road::removeVehicle(TransportMode* vehicle) {
    auto it = std::find(vehicles.begin(), vehicles.end(), vehicle);
    if (it != vehicles.end()) {
        vehicles.erase(it);
        changeState();  // Reevaluate state whenever a vehicle is removed
    }
}

void Road::changeState() {
    // Example logic for changing states based on vehicle count
    if (getVehicleCount() == 0) {
        setState(new EmptyState());
    } else if (getVehicleCount() > 30) {
        setState(new CongestedState());
    } else {
        setState(new NormalState());
    }
    currentState->handleState(this);  // Call handleState based on the current state
}

void Road::setState(TransState* newState) {
    if (currentState) delete currentState;
    currentState = nullptr;
    currentState = newState;
}

int Road::getVehicleCount() {
    return vehicles.size();
}



// TransportFacilities implementations
void Road::maintain() {
    std::cout << "Performing road maintenance" << std::endl;

    // Perform maintenance tasks
    std::cout << "Checking road surface" << std::endl;
    std::cout << "Repairing potholes" << std::endl;
    std::cout << "Maintaining road markings" << std::endl;
}

void Road::useTransport() {
    std::cout << "Road in use by vehicles." << std::endl;
}