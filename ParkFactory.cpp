#include "ParkFactory.h"

/**
 * @brief Constructs a ParkFactory object.
 *
 * Initializes a new instance of the Park building to be used
 * for cloning when creating new Park buildings.
 */
ParkFactory::ParkFactory()
{
    building = new Park();
}

/**
 * @brief Creates and returns a new Park building instance.
 *
 * This method calls the clone method on the Park instance to
 * create a new copy of the Park building. It is part of the
 * Factory Method design pattern.
 *
 * @return Building* A pointer to the newly created Park instance.
 */
Building *ParkFactory::build()
{
    return building->clone();
}
