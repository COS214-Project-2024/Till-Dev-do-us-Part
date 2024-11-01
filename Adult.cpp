#include "Adult.h"
#include "Neutral.h"
#include "SocialAffairsDept.h"
#include "Government.h"

Adult::Adult(){
    mood = new Neutral();
    if(((SocialAffairsDept*)(Government::getInstance()->getDepartment("SocialAffairs")))->getBudget() < 5000){
        std::cout<<" Cannot accept more people into the city. There is not enough money" << std::endl;
    }
    else{
        balance = 5000;
        health = 100;
        netWorth = 0;
        job = nullptr;
    }
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
    //TO BE IMPLEMENTED WITH EVERYTHING ELSE 
}
