/**
 * @file MinorPop.h
 * @brief Defines the MinorPop class, representing a population of Minor citizens.
 * @author Karabo
 */

#ifndef MINORPOP_H
#define MINORPOP_H

#include "Population.h"
#include "Minor.h"

/**
 * @class MinorPop
 * @brief A class that represents a population of Minor citizens.
 * 
 * Inherits from the Population class and provides functionality to create Minor citizens.
 */
class MinorPop : public Population {
public:
    /**
     * @brief Creates and returns a new Minor citizen.
     * 
     * @return Citizen* A pointer to a newly created Minor object.
     */
    virtual Citizen* createPerson() {
        return new Minor(); // Creates and returns a new instance of Minor.
    }
};

#endif // MINORPOP_H