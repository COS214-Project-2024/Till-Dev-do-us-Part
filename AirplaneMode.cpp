#include "AirplaneMode.h"
#include <string>
#include <iostream>


// AirplaneMode implementation
void AirplaneMode::useTransport() {
    // Check flight conditions
    if (state->getState() == "Congested") {
        std::cout << "Flight delayed due to congestion" << std::endl;
        return;
    }

    // Process passenger boarding
    for (auto& passenger : passengers) {
        std::cout << "Airplane boarding passenger" << std::endl;
        passenger->update("Now boarding flight");
    }

    // Update flight schedule and notify
    notifySchedule();
    mediator->notify(this, state);
}