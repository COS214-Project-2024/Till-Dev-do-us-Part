#include "SuburbFactory.h"

/**
 * @class SuburbFactory
 * @brief A factory class for creating Suburb building instances.
 *
 * The SuburbFactory class is responsible for instantiating new
 * Suburb objects using the Factory Method design pattern.
 * It derives from the BuildingFactory base class.
 */
SuburbFactory::SuburbFactory()
{
    // Initialize a new instance of the Suburb building
    building = new Suburb();
}

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
Building *SuburbFactory::build()
{
    return building->clone();
}
