/**
 * @file Adult.cpp
 * @brief Implements the Adult class, which represents an adult citizen with various attributes like mood, balance, health, and employment status.
 * 
 * This file contains the implementation of the Adult class methods, handling properties such as mood, employment, housing, and actions related to work.
 * It also provides placeholder functionality for future implementation.
 * 
 * @note Some functions, such as going to work and managing utilities, have stubs or initial implementations that will be expanded later.
 * 
 * @details The Adult class is part of a simulation involving citizens, their interactions, and their day-to-day routines.
 * 
 * @version 1.1
 * @date Updated: November 4, 2024
 * 
 * Author: Karabo
 */

#include "Adult.h"
#include "Neutral.h"
#include "House.h"

/**
 * @brief Constructs an Adult object and initializes its attributes.
 * 
 * Randomly assigns an initial mood to the Adult object from Neutral, Content, or Distraught.
 * Sets initial values for balance, health, and net worth. The job and house pointers are set to nullptr.
 */
Adult::Adult() {
    int num = rand();
    if (num % 2 == 0)
        mood = new Neutral();
    else if (num % 3 == 0)
        mood = new Content();
    else
        mood = new Distraught();

    balance = 5000;
    health = 100;
    netWorth = 0;
    job = nullptr;
    house = nullptr;
}

/**
 * @brief Changes the mood of the Adult based on the current mood state.
 * 
 * Deletes the current mood and replaces it with a new mood determined by the reaction function.
 * Outputs the updated mood to the console.
 */
void Adult::react() {
    Feeling* newMood = mood->reaction();  
    delete mood;  
    mood = newMood;  
    std::cout << "Person is feeling " << mood->getName() << std::endl;
}

/**
 * @brief Creates a new Adult object as a clone of the current one.
 * 
 * @return Citizen* A pointer to a new Adult object.
 * 
 * @details This method creates a duplicate of the current Adult object, useful for situations requiring an identical instance.
 */
Citizen* Adult::clone() {
    return new Adult();
}

/**
 * @brief Checks if the Adult is employed.
 * 
 * @return true if the Adult has a job; false otherwise.
 * 
 * @details Employment status is determined by whether the job pointer is non-null.
 */
bool Adult::employmentStatus() {
    return job != nullptr;
}

/**
 * @brief Indicates whether the Adult has a child.
 * 
 * @return false, as this implementation assumes no children for Adult instances.
 */
bool Adult::hasChild() {
    return false;
}

/**
 * @brief Adds a specified salary to the Adult's balance.
 * 
 * @param salary The amount to add to the Adult's balance.
 */
void Adult::salary(float salary) {
    balance += salary;
}

/**
 * @brief Sets the job for the Adult.
 * 
 * @param job A pointer to a Business object representing the Adult's employment.
 * 
 * @note This allows for assigning or changing the Adult's employment status.
 */
void Adult::setJob(Business* job) {
    this->job = job;
}

/**
 * @brief Assigns a house to the Adult and adds the Adult as an occupant of the house.
 * 
 * @param h A pointer to the Building object representing the Adult's house.
 * 
 * @details This function sets the house pointer and registers the Adult as an occupant.
 */
void Adult::setHouse(Building* h) {
    house = h;
    balance -= 1000;
    netWorth += 1000;
    house->addOccupant(this);
}

/**
 * @brief Checks if the Adult has a house assigned.
 * 
 * @return true if the Adult has a house; false otherwise.
 */
bool Adult::hasHouse() {
    return house != nullptr;
}

/**
 * @brief Retrieves the house assigned to the Adult.
 * 
 * @return Building* A pointer to the house if assigned, or outputs a message if no house is assigned.
 */
Building* Adult::getHouse() {
    if (house)
        return house;
    else {
        std::cout << "No house allocated" << std::endl;
        return nullptr;
    }
}

/**
 * @brief Prepares the Adult to go to work, simulating various home activities.
 * 
 * Checks if the Adult has a house, and if so, simulates shower, toilet, and stove usage, requesting utilities if needed.
 * Outputs an error message if no house is available.
 * 
 * @note The method is currently a stub and requires implementation for transport to work.
 */
void Adult::goToWork() {
    if (house) {
        if (!((House*)house)->useShower()) {
            house->requestWater(1000);
            house->requestElectricity(1000);
        }
        if (!((House*)house)->useToilet()) {
            house->requestWater(1000);
            house->requestElectricity(1000);
        }
        if (!((House*)house)->useStove()) {
            house->requestElectricity(1000);
        }
    } else {
        std::cout << "Person cannot prepare to go to work." << std::endl;
    }
    // Transport to work will be implemented here in future versions
}

/**
 * @brief Deducts a specified amount from the current balance or budget.
 * 
 * This function reduces the adults's available funds by the provided amount.
 * 
 * @param amount The amount to be deducted.
 */
void Adult::spendMoney(float amount)
{
    if (amount > balance)
    {
        cout << "Citizen does not have enough money to spend" << endl;
        return; 
    }
    balance -= amount; 
}
