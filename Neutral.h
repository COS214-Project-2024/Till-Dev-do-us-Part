/**
 * @file Neutral.h
 * @brief Defines the Neutral class, representing a neutral feeling state and its associated reactions.
 * @author Karabo
 */

#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "Feeling.h"
#include "Content.h"
#include "Distraught.h"
#include <cstdlib>

/**
 * @class Neutral
 * @brief A class that represents a neutral feeling state in the emotional model.
 * 
 * Inherits from the Feeling class and provides functionality for generating reactions based on the neutral state.
 */
class Neutral : public Feeling {
public:
    /**
     * @brief Constructs a Neutral object, initializing its name to "Neutral".
     */
    Neutral();

    /**
     * @brief Generates a reaction based on the Neutral feeling state.
     * 
     * Randomly determines a new feeling state (either Content or Distraught) and returns it.
     * 
     * @return Feeling* A pointer to a new Feeling object representing the new mood.
     */
    virtual Feeling* reaction() override; 
};

#endif // NEUTRAL_H
