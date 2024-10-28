#include "CarMode.h"
#include <string>
#include <iostream>


// CarMode implementation
void CarMode:: useTransport() {
    // Check road conditions
    if (state->getState() == "Congested") {
        std::cout << "Heavy traffic on road" << std::endl;
        return;
    }

    // Process passenger transport
    for (auto& passenger : passengers) {
        std::cout << "Car transporting passenger" << std::endl;
        passenger->update("Car journey in progress");
    }

    // Update mediator
    mediator->notify(this, state);
}

void alertAccident() {
        std::cout << "Car accident reported!" << std::endl;
        setState(new CongestedState(this));
        mediator->notify(this, state);
    }

    void pickUpPassengers() override {
        if (passengers.size() < maxPassengers && isAvailable) {
            std::cout << "Car ready for pickup" << std::endl;
        } else {
            std::cout << "Car is full or unavailable" << std::endl;
        }
    }

    void dropOffPassengers() override {
        if (!passengers.empty()) {
            std::cout << "Dropping off car passengers" << std::endl;
            passengers.clear();
            isAvailable = true;
        }
    }
