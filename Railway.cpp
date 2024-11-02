#include "Railway.h"
#include "EmptyState.h"
#include "NormalState.h"
#include "CongestedState.h"
#include <iostream>
#include <string>
#include <algorithm>

Railway:: Railway(){
    std::cout << "Building Railway." << std::endl;
    currentState= new EmptyState;
}

// Railway::Railway(TransState* state) : TransportFacilities(state) {}

Railway::~Railway() {
    delete currentState;
    trains.clear();
}

void Railway::setState(TransState* newState) {
    if (currentState) delete currentState;
    currentState = nullptr;
    currentState = newState;
}



void Railway::maintain() {
    std::cout << "Performing railway maintenance" << std::endl;
   
    // Perform maintenance tasks
    std::cout << "Checking rail tracks" << std::endl;
    std::cout << "Testing signals" << std::endl;
    std::cout << "Maintaining power lines" << std::endl;
}

