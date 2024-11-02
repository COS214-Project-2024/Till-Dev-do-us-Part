#include "TrainMode.h"
#include "TransState.h"
#include "TransportFacilities.h"
#include <string>
#include <iostream>


TrainMode::TrainMode() {
    mediator=nullptr;
    facility=nullptr;
}

void TrainMode::drive(){
    facility->add(this);
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

std::string TrainMode:: getName() const {
     return "TrainMode"; }

void TrainMode::SendMessage(const std::string& state){
    if (state == "accident") {
        std::cout << this->getName()<< ": Responding to accident. Delaying trips and Notifying other vehicles.\n";
        if(GetFacility()->getModeCount()>10){
            GetFacility()->changeState();   
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

        if(GetFacility()->getModeCount()>10){
            GetFacility()->changeState();  
        }
    }

} 
void TrainMode::stopdrive(){
    facility->remove(this);
}
std::string TrainMode::GetMessage(){
return state;
}