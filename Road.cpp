#include "Road.h"
#include "EmptyState.h"
#include "NormalState.h"
#include "CongestedState.h"
#include "TransState.h"
#include "TransportMode.h" 
#include <iostream>
#include <algorithm>
#include <string>

Road:: Road(){
    std::cout << "Building Road." << std::endl;
    currentState= new EmptyState;
    
}

// Road::Road(TransState* state) : TransportFacilities(state) {}

Road::~Road() {
    delete currentState;
    vehicles.clear();
}

void Road::setState(TransState* newState) {
    if (currentState) delete currentState;
    currentState = nullptr;
    currentState = newState;
}

// TransportFacilities implementations
void Road::maintain() {
    std::cout << "Performing road maintenance" << std::endl;

    // Perform maintenance tasks
    std::cout << "Checking road surface" << std::endl;
    std::cout << "Repairing potholes" << std::endl;
    std::cout << "Maintaining road markings" << std::endl;
}

