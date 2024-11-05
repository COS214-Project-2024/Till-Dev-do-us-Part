#include "MallFactory.h"

/**
 * @class MallFactory
 * @brief A factory class for creating Mall buildings.
 *
 * This class inherits from BuildingFactory and provides functionality
 * to create new instances of Mall.
 */

/**
 * @brief Constructs a MallFactory object.
 *
 * This constructor initializes a new Mall building.
 */
MallFactory::MallFactory()
{
    building = new Mall();
}

/**
 * @brief Creates and returns a new Mall building.
 *
 * This method uses the clone method of the existing Mall instance
 * to create a new building object.
 *
 * @return Building* A pointer to the newly created Mall instance.
 */
Building *MallFactory::build()
{
    return building->clone();
}
