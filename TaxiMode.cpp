#include "TaxiMode.h"
#include "TransportFacilities.h"
#include "TaxiRankIterator.h"
#include <string>
#include <iostream>
#include "ModeFactory.h"

// void TaxiMode::useTransport() {
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

TaxiMode::TaxiMode(){
    TransportMode* Cab= new TaxiMode;
    road->addVehicle(Cab);
}
TaxiMode::TaxiMode(TransportationMediator* mediator, TransportFacilities* facility)
    : TransportMode(mediator), facility(facility) {}

void TaxiMode::alertAccident() {
    std::cout << "TaxiMode: Accident reported. Notifying other road users.\n";
    mediator->notify(this, "accident");
}

void TaxiMode::manageTraffic(const std::string& state) {
    if (state == "accident") {
        std::cout << "TaxiMode: Responding to accident. Slowing down traffic.\n";
    }
    // Additional traffic management logic
}

void TaxiMode::set(const std::string& state) {
    manageTraffic(state);
}

void TaxiMode::changed(const std::string& state) {
    mediator->notify(this, state);
}

std::string TaxiMode:: getName() const {
     return "TaxiMode"; }

TransportFacilities* TaxiMode:: getFacility() const { 
    return facility; }

bool TaxiMode:: isRoadMode() const{
    return true; }

bool TaxiMode::isRailwayMode() const { 
    return false; }

bool TaxiMode:: isAirportMode() const { 
    return false; }

// Iterator??
void TaxiMode::addTaxiRank(TransportStation* rank) {
    taxiRanks.push_back(rank);
}

TransportationIterator* TaxiMode::createIterator() {
    return new TaxiRankIterator(taxiRanks);
}

// CitizenObserver
void TaxiMode::setSchedule(const std::string& newSchedule) {
    schedule = newSchedule;
    notifyScheduleChange();
}

std::string TaxiMode::getSchedule() const {
    return schedule;
}

void TaxiMode::notifyScheduleChange() {
    notifyObservers("Taxi schedule updated: " + schedule);
}