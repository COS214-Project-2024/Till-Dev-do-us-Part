#include "TaxiRank.h"
#include <iostream>

void TaxiRank::handlePassengers() {
    std::cout << "Handling passengers at the Taxi Rank." << std::endl;
}

void TaxiRank::manageFreight() {
    std::cout << "Managing freight at the Taxi Rank." << std::endl;
}

void TaxiRank::maintain() {
    std::cout << "Performing Taxi Rank maintenance" << std::endl;
   
    // Maintain taxi rank facilities
        std::cout << "Maintaining taxi rank facilities" << std::endl;
        std::cout << "Checking taxi bays" << std::endl;
        std::cout << "Updating information displays" << std::endl;
}

void TaxiRank:: addTaxi(TransportMode* taxi){
    if (taxi) { // Ensure the bus is not a null pointer
        taxis.push_back(taxi);
        std::cout << "Taxi added to the Taxi Rank." << std::endl;
    } else {
        std::cout << "Cannot add a null bus to the Taxi Rank." << std::endl;
    }

}