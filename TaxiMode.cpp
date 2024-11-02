#include "TaxiMode.h"
#include "TransportFacilities.h"
#include "TaxiRankIterator.h"
#include <string>
#include <iostream>
#include "ModeFactory.h"


TaxiMode::TaxiMode(){

}

// Mediator

void TaxiMode:: drive(){
    road->add(this);
    std::cout<<"Taxi starts driving"<<std::endl;
}

void TaxiMode::stopDrive(){
    road->remove(this);
    std::cout<<"Taxi stops driving"<<std::endl;
}

void TaxiMode::SendMessage(const std::string& state){
    if (state == "accident") {
        std::cout << this->getName()<< ": Responding to accident. Delaying flights and Notifying other planes.\n";
        if(GetFacility()->getModeCount()>10){
            GetFacility()->changeState();

            
        }

    }

    if(state=="safe"){
        std::cout<<"Safe travel";
    }

    if (state == "bad weather") {
        std::cout << this->getName()<< ": Responding to bad weather. Delaying flights and Notifying other planes.\n";
    }

    if (state == "traffic") {
        std::cout << this->getName()<< ": Responding to air traffic. Delaying flights and Notifying other planes.\n";

        if(GetFacility()->getModeCount()>10){
            GetFacility()->changeState();

            
        }
    }
}

std::string TaxiMode::GetMessage(){
return state;
}

std::string TaxiMode:: getName() const {
     return "TaxiMode"; }

// Iterator??


// CitizenObserver
// void TaxiMode::setSchedule(const std::string& newSchedule) {
//     schedule = newSchedule;
//     notifyScheduleChange();
// }

// std::string TaxiMode::getSchedule() const {
//     return schedule;
// }

// void TaxiMode::notifyScheduleChange() {
//     notifyObservers("Taxi schedule updated: " + schedule);
// }