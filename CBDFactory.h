#ifndef CBDFACTORY_H
#define CBDFACTORY_H

#include "BuildingFactory.h"
#include "CBD.h"

/**
 * @brief Factory class for creating CBD (Central Business District) buildings.
 *
 * The CBDFactory class is responsible for producing CBD-type buildings, implementing
 * the build function to instantiate a new CBD building object.
 */
class CBDFactory : public BuildingFactory
{

public:
    /**
     * @brief Constructs a CBDFactory object.
     */
    CBDFactory();

    /**
     * @brief Creates and returns a new CBD building object.
     *
     * @return Building* A pointer to a newly created CBD building.
     */
    Building *build();
};

#endif
