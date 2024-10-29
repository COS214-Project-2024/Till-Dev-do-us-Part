#include "Adult.h"
#include "Neutral.h"

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
