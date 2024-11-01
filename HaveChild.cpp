/**
 * @file HaveChild.cpp
 * @brief Implements the HaveChild class, representing the ability of a Citizen to have children.
 * @author Karabo
 */

#include "HaveChild.h"

/**
 * @brief Constructs a HaveChild object, associating it with a specific adult Citizen.
 * 
 * @param adult A pointer to the Citizen object representing the adult who can have children.
 */
HaveChild::HaveChild(Citizen* adult) {
    person = adult;
    adult = this; // This line may need review; it overwrites the local pointer.
}

/**
 * @brief Assigns a child to the adult Citizen.
 * 
 * @param baby A pointer to the Citizen object representing the child.
 */
void HaveChild::haveChild(Citizen* baby) {
    this->child = baby; // Assigns the child to this instance.
}

/**
 * @brief Destructor for the HaveChild class.
 * 
 * Cleans up the dynamically allocated adult Citizen object to prevent memory leaks.
 */
HaveChild::~HaveChild() {
    delete person; // Deletes the associated adult Citizen.
    person = nullptr; // Sets the pointer to nullptr for safety.
}

/**
 * @brief Checks if the adult Citizen has a child.
 * 
 * @return bool Always returns true, indicating that this class represents a Citizen capable of having children.
 */
bool HaveChild::hasChild() {
    return true; // Indicates that this Citizen has a child.
}
