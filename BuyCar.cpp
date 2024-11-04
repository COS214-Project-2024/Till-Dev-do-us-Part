/**
 * @file BuyCar.cpp
 * @brief Implements the BuyCar decorator class, allowing an Adult to own a car and manage related financials and ownership state for a Citizen class object.
 * 
 * @author Karabo
 */

#include "BuyCar.h"

/**
 * @brief Constructs a BuyCar object that decorates an Adult with car-buying functionality.
 * 
 * @param adult A pointer to a Citizen object, typically an Adult, who is purchasing the car.
 * 
 * @details This constructor takes a Citizen pointer, stores it as the decorated person, 
 * and redirects the adult pointer to point to this BuyCar decorator.
 */
BuyCar::BuyCar(Citizen* adult) {
    person = adult;
    adult = this;
}

/**
 * @brief Assigns a car to the Citizen and adjusts financial attributes accordingly.
 * 
 * @param car A pointer to a Transport object representing the car being bought.
 * 
 * @note This method currently contains placeholders for financial adjustments and should
 * be updated to reduce the Adult's balance and increase net worth based on the car price.
 */
void BuyCar::buyCar(Transport* car) {
    this->car = car;
    balance -= 500;
    netWorth += 500;
}

/**
 * @brief Destructor for the BuyCar class.
 * 
 * Deletes the associated Citizen object and the car, ensuring cleanup of dynamically
 * allocated resources.
 */
BuyCar::~BuyCar() {
    delete person;
    person = nullptr;

    delete car;
    car = nullptr;
}