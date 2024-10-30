#include "CarMode.h"
#include "TransportFacilities.h"
#include <string>
#include <iostream>
#include "ModeFactory.h"


// // CarMode implementation
// void CarMode:: useTransport() {
//     // Check road conditions
//     if (state->getState() == "Congested") {
//         std::cout << "Heavy traffic on road" << std::endl;
//         return;
//     }

//     // Process passenger transport
//     for (auto& passenger : passengers) {
//         std::cout << "Car transporting passenger" << std::endl;
//         passenger->update("Car journey in progress");
//     }

//     // Update mediator
//     mediator->notify(this, state);
// }

// void alertAccident() {
//         std::cout << "Car accident reported!" << std::endl;
//         setState(new CongestedState(this));
//         mediator->notify(this, state);
//     }

//     void pickUpPassengers() override {
//         if (passengers.size() < maxPassengers && isAvailable) {
//             std::cout << "Car ready for pickup" << std::endl;
//         } else {
//             std::cout << "Car is full or unavailable" << std::endl;
//         }
//     }

//     void dropOffPassengers() override {
//         if (!passengers.empty()) {
//             std::cout << "Dropping off car passengers" << std::endl;
//             passengers.clear();
//             isAvailable = true;
//         }
//     }

// Mediator
CarMode::CarMode(TransportationMediator* mediator, TransportFacilities* facility)
    : TransportMode(mediator), facility(facility) {}

void CarMode::alertAccident() {
    std::cout << "CarMode: Accident reported. Notifying other road users.\n";
    mediator->notify(this, "accident");
}

void CarMode::manageTraffic(const std::string& state) {
    if (state == "accident") {
        std::cout << "CarMode: Responding to accident. Slowing down traffic.\n";
    }
    // Additional traffic management logic
}

void CarMode::set(const std::string& state) {
    manageTraffic(state);
}

void CarMode::changed(const std::string& state) {
    mediator->notify(this, state);
}

std::string CarMode:: getName() const {
     return "CarMode"; }

TransportFacilities* CarMode:: getFacility() const { 
    return facility; }

bool CarMode:: isRoadMode() const{
    return true; }

bool CarMode::isRailwayMode() const { 
    return false; }

bool CarMode:: isAirportMode() const { 
    return false; }