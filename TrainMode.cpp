#include "TrainMode.h"
#include "TransState.h"
#include "TransportFacilities.h"
#include <string>
#include <iostream>


TrainMode::~TrainMode() {
    if (railway) {
        railway->remove(this); // Remove from railway on destruction
    }
}

// void TrainMode::useTransport() {
//     std::cout << "Train is using the railway." << std::endl;
//     if (railway) {
//         railway->useTransport();
//     }
// }

// // TrainMode implementation
// void TrainMode::useTransport() {
//     // Verify railway status
//     if (state->getState() == "Congested") {
//         std::cout << "Train service delayed" << std::endl;
//         return;
//     }

//     // Handle passenger boarding
//     for (auto& passenger : passengers) {
//         std::cout << "Train boarding passenger" << std::endl;
//         passenger->update("Now boarding train");
//     }

//     // Update schedule and notify
//     notifySchedule();
//     mediator->notify(this, state);
// }

//Mediator
// TrainMode::TrainMode(TransportationMediator* mediator, TransportFacilities* facility)
//     : TransportMode(mediator), facility(facility) {}


void TrainMode::alertAccident() {
    std::cout << "TrainMode: Accident reported on the railway. Notifying other train users.\n";
    mediator->notify(this, "accident");
}

void TrainMode::manageTraffic(const std::string& state) {
    if (state == "accident") {
        std::cout << "TrainMode: Responding to accident. Slowing down trains.\n";
    }
    // Additional traffic management logic specific to trains
}

void TrainMode::set(const std::string& state) {
    manageTraffic(state);
}

void TrainMode::changed(const std::string& state) {
    mediator->notify(this, state);
}

std::string TrainMode:: getName() const {
     return "TrainMode"; }

// TransportFacilities* TrainMode:: getFacility() const { 
//     return facility; }

bool TrainMode:: isRoadMode() const{
    return false; }

bool TrainMode::isRailwayMode() const { 
    return true; }

bool TrainMode:: isAirportMode() const { 
    return false; }

// Iterator ????
void TrainMode::addTrainStation(TransportStation* station) {
    trainStations.push_back(station);
}

TransportationIterator* TrainMode::createIterator() {
    return new TrainStationIterator(trainStations);
}

// CitizenObserver
void TrainMode::setSchedule(const std::string& newSchedule) {
    schedule = newSchedule;
    notifyScheduleChange();
}

std::string TrainMode::getSchedule() const {
    return schedule;
}

void TrainMode::notifyScheduleChange() {
    notifyObservers("Train schedule updated: " + schedule);
}

void TrainMode:: drive()
{
    railway->add(this);
}
void TrainMode:: stopdrive()
{
    railway->remove(this);
}