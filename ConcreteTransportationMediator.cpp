#include "ConcreteTransportationMediator.h"
#include "TransportMode.h"
#include <iostream>

ConcreteTransportationMediator::ConcreteTransportationMediator() 
    : roadTraffic(0), airTraffic(0), accident(false), roadState("Normal"), airState("Normal") {}

void ConcreteTransportationMediator::notify(TransportMode* mode, const std::string& state) {
    std::cout << "Mediator notified of state change to " << state << std::endl;
    // Update traffic based on state...
}

void ConcreteTransportationMediator::registerMode(TransportMode* mode) {
    modes.push_back(mode);
}

void ConcreteTransportationMediator::manageTraffic() {
    std::cout << "Managing traffic..." << std::endl;
    // Logic to manage traffic goes here...
}