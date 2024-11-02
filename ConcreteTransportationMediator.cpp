#include "ConcreteTransportationMediator.h"
#include "TransportMode.h"
#include <iostream>

int ConcreteTransportationMediator:: getRoadModes(){
    return roadModes.size();
}

int ConcreteTransportationMediator::getRailwayModes(){
    return railwayModes.size();
}

int ConcreteTransportationMediator:: getAirportModes(){
    return airportModes.size();
}


void ConcreteTransportationMediator::registerMode(TransportMode* mode) {
    // // Register mode based on its facility type (Road, Railway, Airport)
    // if (mode->isRoadMode()) {
    //     roadModes.push_back(mode);
    // } else if (mode->isRailwayMode()) {
    //     railwayModes.push_back(mode);
    // } else if (mode->isAirportMode()) {
    //     airportModes.push_back(mode);
    // }
}

void ConcreteTransportationMediator::notify(TransportMode* mode) {
    std::cout << mode->getName() << " reported a "<<  mode->GetMessage()<< ". Notifying colleagues...\n";

    std::string message= mode->GetMessage();

    if (mode->isRoadM                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ode()) {
        //must look something like mode->getRoad()->getVehicles
   mmm,      for (auto& colleague : mode->GetRoad()->get) {
            if (colleague != mode) {
                colleague->SendMessage(message); // Notify all road colleagues
            }
        }
    } else if (mode->isRailwayMode()) {
        for (auto& colleague : railwayModes) {
            if (colleague != mode) {
                colleague->SendMessage(message); // Notify all railway colleagues
            }
        }
    } else if (mode->isAirportMode()) {
        for (auto& colleague : airportModes) {
            if (colleague != mode) {
                colleague->SendMessage(message); // Notify all airport colleagues
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
