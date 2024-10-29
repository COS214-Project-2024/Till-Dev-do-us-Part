// EmptyState.cpp
#include "EmptyState.h"
#include "TransportFacilities.h"
#include <iostream>

void EmptyState::handleState(TransportFacilities* facility) {
    std::cout << "No traffic - operating under empty conditions." << std::endl;
    // Additional logic if necessary
}

void changeState(TransState newState);