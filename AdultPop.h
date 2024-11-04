/**
 * @file AdultPop.h
 * @brief Defines the AdultPop class, a specialized population class for creating Adult citizens in the system.
 * @author Karabo
 */

#ifndef ADULTPOP_H
#define ADULTPOP_H

#include "Population.h"
#include "Adult.h"

/**
 * @class AdultPop
 * @brief Represents a population that consists solely of Adult citizens.
 * 
 * Inherits from the Population class and overrides the createPerson method to return an Adult instance.
 */
class AdultPop : public Population {

public:
    /**
     * @brief Creates and returns a new Adult instance.
     * 
     * @return Citizen* A pointer to a new Adult object.
     * 
     * @details This method overrides the createPerson function in the Population class, specializing it to create Adult citizens.
     */
    virtual Citizen* createPerson() override {
        return new Adult();
    }

};

#endif // ADULTPOP_H