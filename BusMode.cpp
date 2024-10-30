#include "BusMode.h"
#include "BusIterator.h"
#include <string>
#include <iostream>

// void BusMode::useTransport() {
//     // Check if state is valid for transport
//     if (state->getState() == "Congested") {
//         std::cout << "Bus service delayed due to congestion" << std::endl;
//         return;
//     }

//     // Process passenger boarding
//     for (auto& passenger : passengers) {
//         std::cout << "Bus boarding passenger" << std::endl;
//         passenger->update("Now boarding bus");
//     }

//     // Update schedule and notify mediator
//     notifySchedule();
//     mediator->notify(this, state);
// }




// Mediator
BusMode::BusMode(TransportationMediator* mediator, TransportFacilities* facility)
    : TransportMode(mediator), facility(facility) {}

void BusMode::alertAccident() {
    std::cout << "BusMode: Accident reported. Notifying other road users.\n";
    mediator->notify(this, "accident");
}

void BusMode::manageTraffic(const std::string& state) {
    if (state == "accident") {
        std::cout << "BusMode: Responding to accident. Slowing down traffic.\n";
    }
    // Additional traffic management logic
}

void BusMode::set(const std::string& state) {
    manageTraffic(state);
}

void BusMode::changed(const std::string& state) {
    mediator->notify(this, state);
}

std::string BusMode:: getName() const {
     return "BusMode"; }

TransportFacilities* BusMode:: getFacility() const { 
    return facility; }

bool BusMode:: isRoadMode() const{
    return true; }

bool BusMode::isRailwayMode() const { 
    return false; }

bool BusMode:: isAirportMode() const { 
    return false; }

// Iterator
BusMode::BusMode() {
    // Initialize bus stops if needed
}

void BusMode::addBusStop(TransportStation* stop) {
    busStops.push_back(stop);
}

TransportationIterator* BusMode::createIterator() {
    return new BusIterator(busStops);
}

//CitizenObserver
void BusMode::setSchedule(const std::string& newSchedule) {
    schedule = newSchedule;
    notifyScheduleChange();
}

std::string BusMode::getSchedule() const {
    return schedule;
}

void BusMode::notifyScheduleChange() {
    notifyObservers("Bus schedule updated: " + schedule);
}