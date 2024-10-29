#include "TrainMode.h"
#include "TransState.h"
#include <string>
#include <iostream>

TrainMode::TrainMode(Railway* railway, const std::string& name, double speed, double capacity)
    : TransportMode(name, speed, capacity), railway(railway) {
    if (railway) {
        railway->addTrain(this); // Add to railway on creation
    }
}

TrainMode::~TrainMode() {
    if (railway) {
        railway->removeTrain(this); // Remove from railway on destruction
    }
}

void TrainMode::useTransport() {
    std::cout << "Train is using the railway." << std::endl;
    if (railway) {
        railway->useTransport();
    }
}

// // TrainMode implementation
// void TrainMode::useTransport() {
//     // Verify railway status
//     if (state->getState() == "Congested") {
//         std::cout << "Train service delayed" << std::endl;
//         return;
//     }

//     // Handle passenger boarding
//     for (auto& passenger : passengers) {
//         std::cout << "Train boarding passenger" << std::endl;
//         passenger->update("Now boarding train");
//     }

//     // Update schedule and notify
//     notifySchedule();
//     mediator->notify(this, state);
// }