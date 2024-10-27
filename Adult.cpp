#include "Adult.h"
#include "Neutral.h"

Adult::Adult(){
    mood = new Neutral();
    balance, netWorth, employer = 0;
    //If name will be used, need to pass in as parameter
}

Citizen* Adult::clone(){
    return new Adult();
}

void Adult::react(){
    mood->reaction();
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