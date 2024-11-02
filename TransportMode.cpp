#include "TransportMode.h"
#include "CitizenObserver.h"
#include <algorithm>

// TransportFacilities* TransportMode:: GetFacility(){
//     return this->facility;
// }

// TransportMode* TransportMode:: GetMode(){
//     return this->mode;

// }

void TransportMode::changed(const std::string& state){
    this->state = state;

    if(state=="safe"){
        std::cout<<"Safe travel";
        depart();
    }
    else{
        mediator->notify(this);
}

void TransportMode::divertingRoute(){
    
    for(auto facility: transDept->getDeptFacilities()){
        if(facility->getState()->getStateName()!="Congested")
        {
            SetFacilities(facility);
            return;
        }
    }
}


void TransportMode::SetFacilities(TransportFacilities* facility)
{
    this->facility=facility;
    facility->add(this);
}


// Mediator
void TransportMode::AttachMediator(ConcreteTransportationMediator* newMediator){
    this->mediator= mediator;
    this->mediator->registerMode(this);
}

void TransportMode::addObserver(CitizenObserver* observer) {
    observers.push_back(observer);
}

void TransportMode::removeObserver(CitizenObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void TransportMode::notifyObservers(const std::string& message) {
    for (CitizenObserver* observer : observers) {
        observer->update(message);
    }
}
std::list<TransportStation*> TransportMode:: getStops()
{
    return stops;
}
