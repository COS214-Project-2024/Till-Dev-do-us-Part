#include <iostream>

#include "Citizen.h"

int Citizen::getHealth() {
    return health;
}

void Citizen::setHealth(int h) {
    health = h;
}

std::string Citizen::getFeeiling(){
    return mood->getName();
}

Citizen::~Citizen() {
    delete mood;
    mood = nullptr;
}
