#ifndef FACTORYFACTORY_H
#define FACTORYFACTORY_H

#include "BuildingFactory.h"
#include "Factory.h"

/**
 * @class FactoryFactory
 * @brief A factory class for creating Factory building objects.
 *
 * This class derives from BuildingFactory and implements the method to create
 * instances of the Factory building.
 */
class FactoryFactory : public BuildingFactory
{

public:
    /**
     * @brief Constructs a FactoryFactory object.
     *
     * This constructor initializes a new instance of the Factory building.
     */
    FactoryFactory();

    /**
     * @brief Creates and returns a clone of the Factory object.
     *
     * @return Building* A pointer to a new instance of Factory.
     */
    Building *build();
};

#endif
