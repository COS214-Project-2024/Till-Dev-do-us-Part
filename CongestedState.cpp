// CongestedState.cpp
#include "CongestedState.h"
#include "TransportFacilities.h"
#include <iostream>

CongestedState::CongestedState(){
    name= "CongestedState";
}

void CongestedState::handleState() {
    std::cout << "Operating under congested conditions." << std::endl;
    std::cout << "Implementing congestion management protocols." << std::endl;
    stateFacility->decreaseTraffic();
}

void CongestedState::changeState() {
    if (stateFacility->getModeCount() == 0) {
        stateFacility->setState(new EmptyState());
    } 
    else if (stateFacility->getModeCount() > 10) {
        stateFacility->setState(new CongestedState());
        

    }
    else {
        stateFacility->setState(new NormalState());
    }
    stateFacility->getState()-> handleState();  // Call handleState based on the current state
}
