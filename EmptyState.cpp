// EmptyState.cpp
#include "EmptyState.h"
#include "TransportFacilities.h"
#include <iostream>

EmptyState:: EmptyState(){
    name= "EmptyState";
}

void EmptyState::handleState() {
    std::cout << "No traffic - operating under empty conditions." << std::endl;
    // Additional logic if necessary
}

void changeState(TransState newState);