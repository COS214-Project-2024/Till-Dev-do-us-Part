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

std::list<TransportStation*> TransportMode:: getStops()
{
    return stops;
}
