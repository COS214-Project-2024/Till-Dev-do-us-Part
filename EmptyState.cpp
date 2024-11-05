// EmptyState.cpp
#include "EmptyState.h"
#include "TransportFacilities.h"
#include <iostream>

EmptyState:: EmptyState(TransportFacilities*f){
    name= "EmptyState";
    std::cout<<"Setting Empty state"<<std:: endl;
    stateFacility=f;
}

void EmptyState::handleState() {
    std::cout << "No traffic - operating under empty conditions." << std::endl;
}

void EmptyState::changeState() {
    // std::cout<<"change 1"<<std:: endl;
    if (stateFacility->getModeCount() == 0) {
        //  std::cout<<"change 2"<<std:: endl;
        stateFacility->setState(new EmptyState(stateFacility));
        //  std::cout<<"change 3"<<std:: endl;
    } 
    
    else if (stateFacility->getModeCount() > 10) {
        //  std::cout<<"change 4"<<std:: endl;
        stateFacility->setState(new CongestedState(stateFacility));
        

    }
    else {
        //  std::cout<<"change 5"<<std:: endl;
        stateFacility->setState(new NormalState(stateFacility));
        // std::cout<<"change "<<std:: endl;

    }
    stateFacility->getState()-> handleState();  // Call handleState based on the current state
}