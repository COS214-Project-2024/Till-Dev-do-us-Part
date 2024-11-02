// NormalState.cpp
#include "NormalState.h"
#include "TransportFacilities.h"
#include <iostream>

NormalState:: NormalState(TransportFacilities* f){
    name= "NormalState";
    stateFacility=f;
}

void NormalState::handleState() {
    std::cout << "Operating under normal conditions." << std::endl;
    // Implement any additional logic if necessary
}

void NormalState::changeState() {
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
