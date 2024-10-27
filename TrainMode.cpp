#include "TrainMode.h"
#include "TransState.h"
#include <string>
#include <iostream>

// TrainMode implementation
void TrainMode::useTransport() {
    // Verify railway status
    if (state->getState() == "Congested") {
        std::cout << "Train service delayed" << std::endl;
        return;
    }

    // Handle passenger boarding
    for (auto& passenger : passengers) {
        std::cout << "Train boarding passenger" << std::endl;
        passenger->update("Now boarding train");
    }

    // Update schedule and notify
    notifySchedule();
    mediator->notify(this, state);
}