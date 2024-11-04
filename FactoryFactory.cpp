#include "FactoryFactory.h"

FactoryFactory::FactoryFactory()
{
    // Initialize a new instance of the Factory building.
    building = new Factory();
}

/**
 * @brief Creates and returns a clone of the Factory object.
 *
 * This method calls the clone method of the Factory instance to create a new
 * instance of the Factory building.
 *
 * @return Building* A pointer to a new instance of Factory.
 */
Building *FactoryFactory::build()
{
    return building->clone();
}
