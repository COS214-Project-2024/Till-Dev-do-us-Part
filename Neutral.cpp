/**
 * @file Neutral.cpp
 * @brief Implements the Neutral class, representing a neutral feeling state and its reactions.
 * @author Karabo
 */

#include "Neutral.h"

/**
 * @brief Constructs a Neutral object, initializing its name to "Neutral".
 */
Neutral::Neutral() {
    name = "Neutral"; // Sets the name of the feeling to Neutral.
}

/**
 * @brief Generates a reaction based on the Neutral feeling state.
 * 
 * Randomly determines a new feeling state (either Content or Distraught) and returns it.
 * 
 * @return Feeling* A pointer to a new Feeling object representing the new mood.
 */
Feeling* Neutral::reaction() {
    int num = rand(); // Generates a random number.
    if ((num % 2) == 0)
        return new Content();   // Returns a new Content feeling if the number is even.
    else
        return new Distraught(); // Returns a new Distraught feeling if the number is odd.
}