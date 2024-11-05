#include "EstateFactory.h"

/**
 * @brief Constructs an EstateFactory object.
 *
 * Initializes the factory by creating a new Estate object.
 */
EstateFactory::EstateFactory()
{
    building = new Estate();
}

/**
 * @brief Creates and returns a clone of the Estate object.
 *
 * This method calls the clone function on the existing Estate object to produce
 * a new instance, ensuring that each call to build() generates a distinct Estate.
 *
 * @return Building* A pointer to a new instance of Estate.
 */
Building *EstateFactory::build()
{
    return building->clone();
}
