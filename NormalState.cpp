// NormalState.cpp
#include "NormalState.h"
#include "TransportFacilities.h"
#include <iostream>

NormalState:: NormalState(){
    name= "NormalState";
}

void NormalState::handleState() {
    std::cout << "Operating under normal conditions." << std::endl;
    // Implement any additional logic if necessary
}
