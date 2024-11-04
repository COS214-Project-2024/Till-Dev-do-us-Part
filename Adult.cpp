#include "Adult.h"
#include "Neutral.h"
#include <iostream>

Adult::Adult(){
    mood = new Neutral();
    ///check dept money
    balance = 1000;
    health = 100;
    netWorth = 0;
    job = nullptr;
}

void Adult::react() {
    Feeling* newMood = mood->reaction();  
    delete mood;  
    mood = newMood;  
    std::cout << "Person is feeling " << mood->getName() << std::endl;
}

Citizen* Adult::clone(){
    return new Adult();
}

bool Adult::employmentStatus(){
    return job ? true:false;
}

bool Adult::hasChild(){
    return false;
}

void Adult::salary(float salary){
    balance += salary;
}

void Adult::setJob(Business* job){
    this->job = job;
}

void Adult::goToWork(){
    
}

// CitizenObserver
Adult::Adult(const std::string& name) : name(name) {}

void Adult::update(const std::string& message) {
    std::cout << "Notification for Adult " << name << ": " << message << std::endl;
}
