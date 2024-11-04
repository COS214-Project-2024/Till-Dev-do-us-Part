#include "Minor.h"
#include "Content.h"
#include <iostream>

Minor::Minor(){
    mood = new Content(); 
    health = 100;
}

Citizen* Minor::clone(){
    return new Minor();
}

void Minor::setParent(Adult* p){
    parent = p;
}

void Minor::react(){
    Feeling* newMood = mood->reaction();
    delete mood;  
    mood = newMood;
    std::cout << "Minor is feeling " << mood->getName() << std::endl;
}

void Minor::goToSchool(){
    //Need to decide on implementation
}

// CitizenObserver
Minor::Minor(const std::string& name) : name(name) {}

void Minor::update(const std::string& message) {
    std::cout << "Notification for Minor " << name << ": " << message << std::endl;
}
