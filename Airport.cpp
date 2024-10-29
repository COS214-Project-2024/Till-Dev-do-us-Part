#include "Airport.h"
#include "EmptyState.h"
#include "NormalState.h"
#include "CongestedState.h"
#include <string>
#include <iostream>
#include <algorithm>

Airport::Airport(TransState* state) : TransportFacilities(state) {}

Airport::~Airport() {
    delete currentState;
}

void Airport::addPlane(TransportMode* plane) {
    planes.push_back(plane);
    changeState();  // Reevaluate state whenever a plane is added
}

void Airport::removePlane(TransportMode* plane) {
    auto it = std::find(planes.begin(), planes.end(), plane);
    if (it != planes.end()) {
        planes.erase(it);
        changeState();  // Reevaluate state whenever a plane is removed
    }
}

void Airport::changeState() {
    if (getPlaneCount() == 0) {
        setState(new EmptyState());
    } else if (getPlaneCount() > 3) {
        setState(new CongestedState());
    } else {
        setState(new NormalState());
    }
    currentState->handleState(this);  // Call handleState based on the current state
}

void Airport::setState(TransState* newState) {
    if (currentState) delete currentState;
    currentState = newState;
}

int Airport::getPlaneCount() {
    return planes.size();
}

void Airport::maintain() {
    std::cout << "Performing airport maintenance" << std::endl;

    // Perform maintenance tasks
    std::cout << "Inspecting runways" << std::endl;
    std::cout << "Checking navigation systems" << std::endl;
    std::cout << "Maintaining terminal facilities" << std::endl;
    std::cout << "Testing emergency systems" << std::endl;
}

void Airport::useTransport() {
    std::cout << "Airport in use by airplanes." << std::endl;
}

