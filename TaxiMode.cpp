#include "TaxiMode.h"
#include "TransportFacilities.h"
#include <string>
#include <iostream>
#include "ModeFactory.h"


TaxiMode::TaxiMode(){
    mediator=nullptr;
    facility=nullptr;
}

// Mediator

void TaxiMode::drive() {
    facility->add(this);
    std::cout << "Taxi starts driving" << std::endl;
    travel();

    // Use QueueIterator to traverse stops in forward order
    QueueIterator queueIt(this);
    int x = 1;
    while (queueIt.hasNext()) {
        auto current = queueIt.currItem();
        std::cout << "Arriving at stop " << x++ << std::endl;
        queueIt.next();
    }

    std::cout << "Revisiting stops\n";

    // Use StackIterator to traverse stops in reverse order
    StackIterator stackIt(this);
    x = 1; // Reset x for reverse traversal
    while (stackIt.hasNext()) {
        auto current = stackIt.currItem();
        std::cout << "Arriving at stop " << x-- << std::endl;
        stackIt.next();
    }

    std::cout << "Completed all routes" << std::endl;
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
     