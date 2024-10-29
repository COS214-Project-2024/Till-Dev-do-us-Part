#include "ConcreteTransportationMediator.h"
#include "TransportMode.h"
#include <iostream>

void ConcreteTransportationMediator::registerMode(TransportMode* mode) {
    // Register mode based on its facility type (Road, Railway, Airport)
    if (mode->isRoadMode()) {
        roadModes.push_back(mode);
    } else if (mode->isRailwayMode()) {
        railwayModes.push_back(mode);
    } else if (mode->isAirportMode()) {
        airportModes.push_back(mode);
    }
}

void ConcreteTransportationMediator::notify(TransportMode* mode, const std::string& state) {
    std::cout << mode->getName() << " reported a " << state << ". Notifying colleagues...\n";

    if (mode->isRoadMode()) {
        for (auto& colleague : roadModes) {
            if (colleague != mode) {
                colleague->changed(state); // Notify all road colleagues
            }
        }
    } else if (mode->isRailwayMode()) {
        for (auto& colleague : railwayModes) {
            if (colleague != mode) {
                colleague->changed(state); // Notify all railway colleagues
            }
        }
    } else if (mode->isAirportMode()) {
        for (auto& colleague : airportModes) {
            if (colleague != mode) {
                colleague->changed(state); // Notify all airport colleagues
            }
        }
    }
}

void ConcreteTransportationMediator::manageTraffic(TransportMode* originator, const std::string& state) {
    // Logic to manage traffic, which may change the state of Road, Railway, or Airport
    std::cout << "Managing traffic due to " << state << " for " << originator->getName() << "\n";
    auto facility = originator->getFacility();
    if (facility) {
        facility->changeState(state); // Adjusts the state of the facility
    }
}

// void ConcreteTransportationMediator::manageTraffic(TransportMode* originator, const std::string& state) {
//     std::cout << "Managing traffic due to " << state << " for " << originator->getName() << "\n";
//     if (originator->getFacility()) {
//         originator->getFacility()->changeState(state);
//     }
// }
