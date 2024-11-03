#include "Citizen.h"
// #include "Feeling.h"

#include <iostream>

int Citizen::getHealth() {
    return health;
}

void Citizen::setHealth(int h) {
    health = h;
}

Citizen::~Citizen() {
    delete mood;
    mood = nullptr;
}
