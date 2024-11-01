/**
 * @file Citizen.cpp
 * @brief Implements the Citizen class, representing a person in the system with attributes such as health and mood.
 * @author Karabo
 */

#include <iostream>
#include "Citizen.h"

/**
 * @brief Retrieves the current health of the Citizen.
 * 
 * @return int The current health value of the Citizen.
 */
int Citizen::getHealth() {
    return health;
}

/**
 * @brief Sets the health of the Citizen to a specified value.
 * 
 * @param h The new health value to assign to the Citizen.
 */
void Citizen::setHealth(int h) {
    health = h;
}

/**
 * @brief Retrieves the name of the current mood of the Citizen.
 * 
 * @return std::string The name of the Citizen's mood.
 */
std::string Citizen::getFeeling() {
    return mood->getName();
}

/**
 * @brief Destructor for the Citizen class.
 * 
 * Cleans up the dynamically allocated mood object to prevent memory leaks.
 */
Citizen::~Citizen() {
    delete mood;
    mood = nullptr;
}
