#ifndef SUBURBFACTORY_H
#define SUBURBFACTORY_H

#include "BuildingFactory.h"
#include "Suburb.h"

/**
 * @class SuburbFactory
 * @brief A factory class for creating instances of Suburb buildings.
 *
 * The SuburbFactory class is responsible for instantiating
 * new Suburb objects using the Factory Method design pattern.
 * It inherits from the BuildingFactory base class and
 * provides a specific implementation for creating suburb
 * buildings.
 */
class SuburbFactory : public BuildingFactory
{

public:
    /**
     * @brief Constructor for SuburbFactory.
     *
     * Initializes a new instance of the SuburbFactory class,
     * creating a new Suburb building instance.
     */
    SuburbFactory();

    /**
     * @brief Creates and returns a new Suburb building instance.
     *
     * This method overrides the build method from the
     * BuildingFactory class to create a new Suburb
     * building by cloning the existing Suburb instance.
     *
     * @return Building* A pointer to the newly created
     * Suburb instance.
     */
    Building *build();
};

#endif
