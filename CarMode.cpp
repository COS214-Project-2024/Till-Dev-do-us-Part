#include "CarMode.h"
#include "TransportFacilities.h"
#include <string>
#include <iostream>
#include "ModeFactory.h"

CarMode::CarMode(){
    mediator=nullptr;
    facility=nullptr;
}

void CarMode::drive(){
    facility->add(this);
    std::cout<<"Car starts driving"<<std::endl;
    travel();
}

void CarMode::stopdrive(){
    facility->remove(this);
    std::cout<<"Car stops driving"<<std::endl;
}

void CarMode::SetTransDept(TransportDept* transDept){
    this->transDept=transDept;
    transDept->addMode("Car",this);

}

void CarMode::SendMessage(std::string state){
    if (state == "accident") {
        std::cout << this->getName()<< ": Responding to accident. Delaying flights and Notifying other planes.\n";
        if(GetFacility()->getModeCount()>10){
            GetFacility()->getState()->changeState();

            
        }

    }

    if(state=="safe"){
        std::cout<<"Safe travels";
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

std::string CarMode::GetMessage(){
return state;
}

std::string CarMode:: getName() const {
     return "CarMode"; }
