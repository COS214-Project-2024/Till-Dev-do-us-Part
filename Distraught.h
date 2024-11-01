/**
 * @file Distraught.h
 * @brief Defines the Distraught class, representing a distressed mood state for a Citizen and its reaction behavior.
 * @author Karabo
 */

#ifndef DISTRAUGHT_H
#define DISTRAUGHT_H

#include "Feeling.h"
#include "Content.h"
#include "Neutral.h"
#include <cstdlib>

/**
 * @class Distraught
 * @brief A class representing a distressed mood state that can produce reactions.
 * 
 * Inherits from the Feeling class and provides a method to generate a reaction
 * that results in either a Content or Neutral mood based on a random decision.
 */
class Distraught : public Feeling {
public:
    /**
     * @brief Constructs a Distraught object, initializing its mood name to "Distraught".
     */
    Distraught();

    /**
     * @brief Generates a reaction that may result in a Content or Neutral mood.
     * 
     * @return Feeling* A pointer to a new Feeling object representing the resulting mood.
     * 
     * @details This method uses a random number generator to decide which mood to return.
     */
    virtual Feeling* reaction();
};

#endif // DISTRAUGHT_H
