#include "Adult.h"
#include "Neutral.h"

Adult::Adult(){
    mood = new Neutral();
    balance = 1000;
    netWorth, employer = 0;
}

Citizen* Adult::clone(){
    return new Adult();
}

bool Adult::employmentStatus(){
    return employer ? true:false;
}

void Adult::salary(float salary){
    balance += salary;
}

//Used in department
void Adult::setEmployer(Business* employer){
    this->employer = employer;
}

void Adult::goToWork(){
    
}