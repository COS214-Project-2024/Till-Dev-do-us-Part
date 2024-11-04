/**
 * @file Distraught.cpp
 * @brief Implements the Distraught class, representing a distressed mood state for a Citizen and its reaction behavior.
 * @author Karabo
 */

#include "Distraught.h"

/**
 * @brief Constructs a Distraught object, initializing its mood name.
 * 
 * The default name is set to "Distraught" to represent a distressed mood state.
 */
Distraught::Distraught() {
    name = "Distraught";
}

/**
 * @brief Generates a reaction based on a random number to determine the resulting mood state.
 * 
 * @return Feeling* A pointer to a new Feeling object representing the Citizen's mood,
 *         which can be either Content or Neutral based on a random decision.
 * 
 * @details This method uses a random number generator to determine whether to return
 *          a Content mood for even numbers or a Neutral mood for odd numbers.
 */
Feeling* Distraught::reaction() {
    int num = rand();
    if ((num % 2) == 0)
        return new Content();
    else
        return new Neutral();
}