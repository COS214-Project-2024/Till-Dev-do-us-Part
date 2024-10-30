#include "AirplaneMode.h"
#include <string>
#include <iostream>



// // AirplaneMode implementation
// void AirplaneMode::useTransport() {
//     // Check flight conditions
//     if (state->getState() == "Congested") {
//         std::cout << "Flight delayed due to congestion" << std::endl;
//         return;
//     }

//     // Process passenger boarding
//     for (auto& passenger : passengers) {
//         std::cout << "Airplane boarding passenger" << std::endl;
//         passenger->update("Now boarding flight");
//     }

//     // Update flight schedule and notify
//     notifySchedule();
//     mediator->notify(this, state);
// }

AirplaneMode::AirplaneMode(TransportationMediator* mediator, TransportFacilities* facility)
    : TransportMode(mediator), facility(facility) {}


void AirplaneMode::alertAccident() {
    std::cout << "AirplaneMode: Accident reported at the airport. Notifying other planes.\n";
    mediator->notify(this, "accident");
}

void AirplaneMode::manageTraffic(const std::string& state) {
    if (state == "accident") {
        std::cout << "AirplaneMode: Responding to accident. Delaying flights.\n";
    }
    // Additional traffic management logic specific to trains
}

void AirplaneMode::set(const std::string& state) {
    manageTraffic(state);
}

void AirplaneMode::changed(const std::string& state) {
    mediator->notify(this, state);
}

std::string AirplaneMode:: getName() const {
     return "AirplaneMode"; }

TransportFacilities* AirplaneMode:: getFacility() const { 
    return facility; }

bool AirplaneMode:: isRoadMode() const{
    return false; }

bool AirplaneMode::isRailwayMode() const { 
    return false; }

bool AirplaneMode:: isAirportMode() const { 
    return true; }

// Iterator???

// CitizenObserver
void AirplaneMode::setSchedule(const std::string& newSchedule) {
    schedule = newSchedule;
    notifyScheduleChange();
}

std::string AirplaneMode::getSchedule() const {
    return schedule;
}

void AirplaneMode::notifyScheduleChange() {
    notifyObservers("Airplane schedule updated: " + schedule);
}