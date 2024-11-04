#include "BusMode.h"
#include <string>
#include <iostream>

BusMode:: BusMode()
{
    
    mediator=nullptr;
    transDept= nullptr;
    facility=nullptr;
    state="";
    transDept=nullptr;
}


void BusMode::drive() {
    
    facility->add(this);
    TransportationIterator* queueIt= createQIterator();
    travel();
    int x = 1;

    // Iterate through stops using QueueIterator
    while (queueIt->hasNext()) {
        auto current = queueIt->currItem();
        std::cout << "Arriving at stop " << x++ << std::endl;
        queueIt->next();
    }

    std::cout << "Revisiting stops\n";
    StackIterator stackIt(this); // Use a different variable name for the StackIterator
    x = getStops().size();

    // Iterate through stops in reverse order using StackIterator
    while (stackIt.hasNext()) {
        auto current = stackIt.currItem();
        std::cout << "Arriving at stop " << x-- << std::endl;
        stackIt.next();
    }

    std::cout << "Completed all routes" << std::endl;
}

void BusMode::SetTransDept(TransportDept* transDept){
    this->transDept=transDept;
    transDept->addMode("Bus",this);

}


void BusMode::SendMessage(std::string state){
    if (state == "accident") {
        std::cout << this->getName()<< ": Responding to accident. Delaying trips and Notifying other vehicles.\n";
        std::cout <<"Diverting Traffic\n";
        if(GetFacility()->getModeCount()>10){
            GetFacility()->getState()->changeState();   
        }

    }

    if(state=="safe"){
        std::cout<<"Safe travel";
    }

    if (state == "bad weather") {
        std::cout << this->getName()<< ": Responding to bad weather. Delaying trips and Notifying other vehicles.\n";
    }

    if (state == "traffic") {
        std::cout << this->getName()<< ": Responding to air traffic. Delaying trips and Notifying other vehicles.\n";
        std::cout <<"Diverting Traffic\n";

        if(GetFacility()->getModeCount()>10){
            GetFacility()->getState()->changeState();  
        }
    }

} 
std::string BusMode::GetMessage(){
return state;
}

void BusMode::stopdrive(){
    facility->remove(this);
}

std::string BusMode:: getName() const {
     return "BusMode\n"; 
     }

