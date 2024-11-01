/**
 * @file Content.cpp
 * @brief Implements the Content class, representing a neutral state for a Citizen's mood and defining its reaction behavior.
 * @author Karabo
 */

#include "Content.h"

/**
 * @brief Constructs a Content object, initializing its mood name.
 * 
 * The default name is set to "Content" to represent a neutral mood.
 */
Content::Content() {
    name = "Content";
}

/**
 * @brief Generates a reaction based on a random number to determine mood state.
 * 
 * @return Feeling* A pointer to a new Feeling object representing the Citizen's mood,
 *         which can be either Neutral or Distraught based on a random decision.
 * 
 * @details This method uses a random number generator to determine whether to return
 *          a Neutral or Distraught mood. It produces a Neutral mood for even numbers
 *          and a Distraught mood for odd numbers.
 */
Feeling* Content::reaction() {
    int num = rand();
    if ((num % 2) == 0)
        return new Neutral();
    else
        return new Distraught();
}
