#include "BusStop.h"
#include <iostream>

void BusStop::handlePassengers() {
    std::cout << "Handling passengers at the Bus Stop." << std::endl;
}

void BusStop::manageFreight() {
    std::cout << "Managing freight at the Bus Stop." << std::endl;
}

void BusStop::maintain() {
    std::cout << "Performing Bus Stop maintenance" << std::endl;
   
    // Maintain taxi rank facilities
        std::cout << "Maintaining bus stop facilities" << std::endl;
        std::cout << "Checking bus stop" << std::endl;
        std::cout << "Updating information displays" << std::endl;
}

// void BusStop:: addBus(TransportMode* bus){
//     if (bus) { // Ensure the bus is not a null pointer
//         buses.push_back(bus);
//         std::cout << "Bus added to the Bus Stop." << std::endl;
//     } else {
//         std::cout << "Cannot add a null bus to the Bus Stop." << std::endl;
//     }

// }
