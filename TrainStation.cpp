#include "TrainStation.h"
#include <iostream>
#include <algorithm>

void TrainStation::handlePassengers() {
    std::cout << "Handling passengers at the Train Station." << std::endl;
}

void TrainStation::manageFreight() {
    std::cout << "Managing freight at the Train Station." << std::endl;
}

void TrainStation::maintain() {
    std::cout << "Performing Train Station maintenance" << std::endl;
   
    // Maintain taxi rank facilities
        std::cout << "Maintaining train station facilities" << std::endl;
        std::cout << "Checking train station" << std::endl;
        std::cout << "Updating information displays" << std::endl;
}

// void TrainStation:: addTrain(TransportMode* train){
//     if (train) { // Ensure the bus is not a null pointer
//         trains.push_back(train);
//         std::cout << "Train added to the Train Station." << std::endl;
//     } else {
//         std::cout << "Cannot add a null train to the Train Station." << std::endl;
//     }

// }

