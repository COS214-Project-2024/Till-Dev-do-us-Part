/**
 * @file Population.cpp
 * @brief Implements the Population class, managing a collection of Citizen instances.
 * @author Karabo
 */

#include "Population.h"

/**
 * @brief Creates and returns a new Citizen instance.
 * 
 * This function calls the createPerson() method to generate a new citizen and returns it.
 * 
 * @return Citizen* A pointer to the newly created Citizen object.
 */
Citizen* Population::getPerson() {
    citizen = createPerson(); // Calls the method to create a new citizen.
    return citizen;           // Returns the created citizen.
}

/**
 * @brief Generates an array of cloned Citizen instances.
 * 
 * This function creates a new Citizen and clones it 10 times, returning an array of pointers to these clones.
 * 
 * @return Citizen** A pointer to an array of Citizen pointers, each representing a cloned citizen.
 */
Citizen** Population::reproduce(int num) {
    Citizen** people = new Citizen*[num]; // Allocates an array for 10 citizens.
    citizen = createPerson(); // Creates a new citizen.

    for (int i = 0; i < num; i++) {
        people[i] = citizen->clone(); // Clones the citizen and stores it in the array.
    }

    delete citizen; // Deletes the original citizen to prevent memory leaks.
    return people;  // Returns the array of cloned citizens.
}