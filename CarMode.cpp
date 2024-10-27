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
