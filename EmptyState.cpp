// EmptyState.cpp
#include "EmptyState.h"
#include "TransportFacilities.h"
#include <iostream>

EmptyState:: EmptyState(TransportFacilities*f){
    name= "EmptyState";
    stateFacility=f;
}

void EmptyState::handleState() {
    std::cout << "No traffic - operating under empty conditions." << std::endl;
    // Additional logic if necessary
}

void EmptyState::changeState() {
    if (stateFacility->getModeCount() == 0) {
        stateFacility->setState(new EmptyState(stateFacility));
    } 
    else if (stateFacility->getModeCount() > 10) {
        stateFacility->setState(new CongestedState(stateFacility));
        

    }
    else {
        stateFacility->setState(new NormalState(stateFacility));
    }
    stateFacility->getState()-> handleState();  // Call handleState based on the current state
}