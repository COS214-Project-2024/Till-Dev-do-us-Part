#include "Adult.h"
#include "Neutral.h"
#include "House.h"

Adult::Adult(){

    int num = rand();

    if(num%2==0)
        mood = new Neutral();
    else if(num%3==0)
        mood = new Content();
    else
        mood = new Distraught();

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

void Adult::setHouse(Building* h){
    house = h;
    house->addOccupant(this);
}

void Adult::goToWork(){
    if(!((House*)house)->useShower()){
        house->requestWater(1000);
        house->requestElectricity(1000);
    }
    if(!((House*)house)->useToilet()){
        house->requestWater(1000);
        house->requestElectricity(1000);
    }
    if(!((House*)house)->useStove()){
        house->requestElectricity(1000);
    }
    
    //Need to use transport here

}
