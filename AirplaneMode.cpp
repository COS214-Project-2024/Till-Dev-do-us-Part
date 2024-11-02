#include "AirplaneMode.h"
#include <string>
#include <iostream>

TransportFacilities* AirplaneMode:: GetFacility(){
     return this->airport;
}

void AirplaneMode::depart(){
    airport->remove(this);
    std::cout<<"Airplane is taking-off"<<std::endl;
}
void AirplaneMode::arrive(){
    airport->add(this);
    std::cout<<"Airplane is landing"<<std::endl;
    travel();

}

void AirplaneMode::travel()
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
void AirplaneMode::SetFacilities(Airport* airport){
    this->airport=airport;
    
}

void AirplaneMode::SendMessage(const std::string& state){
    if (state == "accident") {
        std::cout << this->getName()<< ": Responding to accident. Delaying flights and Notifying other planes.\n";
        if(GetFacility()->getModeCount()>10){
            GetFacility()->changeState();

            
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
            GetFacility()->changeState();

            
        }
    }

}
    
std::string AirplaneMode::GetMessage(){
return state;
}


void AirplaneMode::changed(const std::string& state) {
    this->state = state;
    mediator->notify(this);
    
}
    

std::string AirplaneMode:: getName() const {
     return "AirplaneMode"; }


// Iterator???

// CitizenObserver
// void AirplaneMode::setSchedule(const std::string& newSchedule) {
//     schedule = newSchedule;
//     notifyScheduleChange();
// }

// std::string AirplaneMode::getSchedule() const {
//     return schedule;
// }

// void AirplaneMode::notifyScheduleChange() {
//     notifyObservers("Airplane schedule updated: " + schedule);
// }

