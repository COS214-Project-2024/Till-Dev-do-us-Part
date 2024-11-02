#include "TaxiMode.h"
#include "TransportFacilities.h"
#include "TaxiRankIterator.h"
#include <string>
#include <iostream>
#include "ModeFactory.h"


TaxiMode::TaxiMode(){
    mediator=nullptr;
    facility=nullptr;
}

// Mediator

void TaxiMode:: drive(){
    facility->add(this);
    std::cout<<"Taxi starts driving"<<std::endl;
    travel();

    QueueIterator it(this);
    int x=1;
    while (it.hasNext())
    {
        auto current=it.currItem();
        std:: cout<<"Arriving at stop "<<x++<<std::endl;
        it.next();
    }
    std::cout<<"Revisiting stops\n";
    StackIterator it(this);
    int x=1;
    while (it.hasNext())
    {
        auto current=it.currItem();
        std:: cout<<"Arriving at stop "<<x--<<std::endl;
        it.next();
    }
     std::cout<<"Completed all routes";

}

void TaxiMode::stopDrive(){
    facility->remove(this);
    std::cout<<"Taxi stops driving"<<std::endl;
}

void TaxiMode::SendMessage(const std::string& state){
    if (state == "accident") {
        std::cout << this->getName()<< ": Responding to accident. Delaying flights and Notifying other planes.\n";
        if(GetFacility()->getModeCount()>10){
            GetFacility()->getState()->changeState();

            
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
            GetFacility()->getState()->changeState();
            
        }
    }
}

std::string TaxiMode::GetMessage(){
return state;
}

std::string TaxiMode:: getName() const {
     return "TaxiMode"; }
     