#include "AirplaneMode.h"
#include <string>
#include <iostream>


AirplaneMode:: AirplaneMode()
{
    mediator=nullptr;
    facility=nullptr;
}

void AirplaneMode::depart(){
    facility->remove(this);
    std::cout<<"Airplane is departing"<<std::endl;

}
void AirplaneMode::arrive(){
    facility->add(this);
    travel();

}

void AirplaneMode::SendMessage(const std::string& state){
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
std::string AirplaneMode::GetMessage(){
return state;
}

std::string AirplaneMode:: getName() const {
     return "AirplaneMode"; 
}

AirplaneMode::~AirplaneMode(){
    

}
