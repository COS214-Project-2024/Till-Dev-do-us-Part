#include "TransportMode.h"
#include "TransportFacilities.h"
#include "CitizenObserver.h"
#include <algorithm>

TransportMode::~TransportMode(){
    // delete facility;  // Delete the single pointer
    facility = nullptr;

    // delete transDept;  // Delete the single pointer
    transDept = nullptr;

    for (auto obi : observers) {
        //delete obi;
    }
    observers.clear();
}



void TransportMode::changed(std::string state){
   
    this->state = state;
    
    
    mediator->notify(this);

}

void TransportMode::divertingRoute(std::string type){
    std::cout<<"div 1"<<std:: endl;
    
    for(auto facility: transDept->getDeptFacilities(type)){
        std::cout<<"div 2"<<std:: endl;
        if(facility->getState()->getStateName()!="Congested")
        {
            std::cout<<"div 3"<<std:: endl;

            SetFacilities(facility);
            std::cout<<"div 4"<<std:: endl;
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
       std::cout<<"State :"<<state<<std::endl;
       
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

