/**
 * @file Adult.cpp
 * @brief Implements the Adult class, which represents an adult citizen with various attributes like mood, balance, health, and employment status.
 * @author Karabo
 */

#include "Adult.h"
#include "Neutral.h"

/**
 * @brief Constructs an Adult object and initializes its attributes.
 * 
 * Initializes the mood to a neutral state, sets balance, health, and net worth values, and sets job to nullptr.
 * 
 * @note This constructor assumes initial balance, health, and net worth values for an adult citizen.
 */
Adult::Adult() {
    mood = new Neutral();
    /// Check department funds for additional logic (future implementation)
    balance = 1000;
    health = 100;
    netWorth = 0;
    job = nullptr;
}

/**
 * @brief Changes the mood of the Adult based on the current mood state.
 * 
 * Deletes the current mood and replaces it with a new mood based on the reaction function of the current mood. Outputs the updated mood.
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
    return job ? true : false;
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
 * 
 * @note This method can be called to increment the Adult's financial balance.
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
 * @brief Placeholder function for the Adult to go to work.
 * 
 * This function is currently a stub and will be implemented with specific work-related functionality in future versions.
 */
void Adult::goToWork() {
    // TO BE IMPLEMENTED LATER
}
