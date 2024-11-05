#include "HouseFactory.h"

/**
 * @brief Constructs a HouseFactory object.
 *
 * This constructor initializes a new instance of the House building.
 */
HouseFactory::HouseFactory()
{
    building = new House();
}

/**
 * @brief Creates and returns a clone of the House object.
 *
 * This method creates a new instance of the House building by calling
 * the clone method on the existing House object.
 *
 * @return Building* A pointer to a new instance of House.
 */
Building *HouseFactory::build()
{
    return building->clone();
}
