#include "TrainMode.h"
#include "TransState.h"
#include "TransportFacilities.h"
#include <string>
#include <iostream>


TrainMode::TrainMode() {
    mediator=nullptr;
    facility=nullptr;
}

void TrainMode::drive() {
    facility->add(this);
    travel();

    // Use QueueIterator for forward traversal
    QueueIterator queueIt(this);
    int x = 1;
    while (queueIt.hasNext()) {
        auto current = queueIt.currItem();
        std::cout << "Arriving at stop " << x++ << std::endl;
        queueIt.next();
    }

    std::cout << "Revisiting stops\n";

    // Use StackIterator for reverse traversal
    StackIterator stackIt(this);
    x = 1; // Reset x for reverse traversal
    while (stackIt.hasNext()) {
        auto current = stackIt.currItem();
        std::cout << "Arriving at stop " << x-- << std::endl;
        stackIt.next();
    }

    std::cout << "Completed all routes" << std::endl;
}



std::string TrainMode:: getName() const {
     return "TrainMode"; }

void TrainMode::SendMessage(const std::string& state){
    if (state == "accident") {
        std::cout << this->getName()<< ": Responding to accident. Delaying trips and Notifying other vehicles.\n";
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

        if(GetFacility()->getModeCount()>10){
            GetFacility()->getState()->changeState();  
        }
    }

} 
void TrainMode::stopdrive(){
    facility->remove(this);
}
std::string TrainMode::GetMessage(){
return state;
}
