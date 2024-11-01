/**
 * @file Minor.cpp
 * @brief Implements the Minor class, representing a child Citizen with mood and health attributes.
 * @author Karabo
 */

#include "Minor.h"
#include "Content.h"

/**
 * @brief Constructs a Minor object, initializing its mood to Content and health to 100.
 */
Minor::Minor() {
    mood = new Content(); // Sets the initial mood of the Minor to Content.
    health = 100;        // Initializes health to a maximum value.
}

/**
 * @brief Clones the current Minor object.
 * 
 * @return Citizen* A pointer to a new Minor object that is a copy of this Minor.
 */
Citizen* Minor::clone() {
    return new Minor(); // Creates and returns a new instance of Minor.
}

/**
 * @brief Sets the parent of the Minor.
 * 
 * @param p A pointer to the Adult object representing the Minor's parent.
 */
void Minor::setParent(Adult* p) {
    parent = p; // Associates the provided parent with this Minor.
}

/**
 * @brief Triggers a reaction based on the Minor's current mood.
 * 
 * Updates the Minor's mood by calling the reaction method of the current mood,
 * and outputs the new mood's name.
 */
void Minor::react() {
    Feeling* newMood = mood->reaction(); // Get the new mood from the reaction method.
    delete mood;                         // Deletes the old mood to prevent memory leak.
    mood = newMood;                      // Updates the mood to the new mood.
    std::cout << "Minor is feeling " << mood->getName() << std::endl; // Outputs the current mood.
}

/**
 * @brief Placeholder for school-related behavior.
 * 
 * Currently unimplemented; future functionality will define how the Minor interacts with school.
 */
void Minor::goToSchool() {
    // Need to decide on implementation.
}
