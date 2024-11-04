/**
 * @file Content.h
 * @brief Defines the Content class, representing a neutral mood state for a Citizen and its reaction behavior.
 * @author Karabo
 */

#ifndef CONTENT_H
#define CONTENT_H

#include "Feeling.h"
#include "Neutral.h"
#include "Distraught.h"
#include <cstdlib>

/**
 * @class Content
 * @brief A class representing a neutral mood state that can produce reactions.
 * 
 * Inherits from the Feeling class and provides a method to generate a reaction
 * that results in either a Neutral or Distraught mood based on a random decision.
 */
class Content : public Feeling {
public:
    /**
     * @brief Constructs a Content object, initializing its mood name to "Content".
     */
    Content();

    /**
     * @brief Generates a reaction that may result in a Neutral or Distraught mood.
     * 
     * @return Feeling* A pointer to a new Feeling object representing the resulting mood.
     * 
     * @details This method uses a random number generator to decide which mood to return.
     */
    virtual Feeling* reaction();
};

#endif // CONTENT_H