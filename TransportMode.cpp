#include "TransportMode.h"
#include "CitizenObserver.h"
#include <algorithm>


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

TransportationIterator* TransportMode::createQIterator()
{
    return new QueueIterator(this);
}


TransportationIterator* TransportMode::createSIterator()
{
    return new StackIterator(this);
}


void TransportMode::travel()
{
    // Define possible states
        std::vector<std::string> states = {"accident", "bad weather", "traffic","safe"};

    // Shuffle states
    std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(states.begin(), states.end(), gen);

        // Pick the first state in the shuffled list
       state = states.front();
       changed(state);
    
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

 void TransportMode::SetMediator(ConcreteTransportationMediator* mediator)
 {
    this->mediator=mediator;
 }

 void TransportMode:: addStop(TransportStation* stop)
 {
    stops.push_back(stop);
 }

TransportFacilities* TransportMode::GetFacility()
{
    return this->facility;
}

