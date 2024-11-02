#include "Airport.h"
#include "EmptyState.h"
#include "NormalState.h"
#include "CongestedState.h"
#include <string>
#include <iostream>
#include <algorithm>


void Airport::decreaseTraffic(Airport* airport2){
    // reset the the pointer for the plane to a new airport and erase the plane from the vector
    int elementsToDelete = 6; 
    for(int i=0; i< elementsToDelete && !planes.empty(); i++){
        planes[i]->divertingRoute();
        --i;
    }
    


    // if(mediator->getAirportModes()>10){
    //         int elementsToDelete = 5;
    //         for(int i=0; i<elementsToDelete && !airportModes.empty(); i++){
    //             // delete airportModes[i]; // Free memory
    //     airportModes.erase(airportModes.begin() + i); // Remove element from vector
    //     --i; //Adjust index after erase to account for shifting elements

    //         } 
    // }
}

Airport::Airport(){
    std::cout << "Building Airport." << std::endl;
    currentState= new EmptyState();
}

// Airport::Airport(TransState* state) : TransportFacilities(state) {}

Airport::~Airport() {
    delete currentState;
    planes.clear();
}



void Airport::maintain() {
    std::cout << "Performing Airport maintenance" << std::endl;

    // Perform maintenance tasks
    std::cout << "Inspecting runways" << std::endl;
    std::cout << "Checking navigation systems" << std::endl;
    std::cout << "Maintaining terminal facilities" << std::endl;
    std::cout << "Testing emergency systems" << std::endl;
}

    
