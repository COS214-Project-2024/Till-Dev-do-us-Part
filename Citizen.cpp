#include <iostream>

#include "Citizen.h"

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
