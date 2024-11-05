#include "CBDFactory.h"

/**
 * @brief Constructs a CBDFactory object.
 *
 * This constructor initializes a new instance of the CBDFactory,
 * creating a CBD building instance.
 */
CBDFactory::CBDFactory()
{
    building = new CBD();
}

/**
 * @brief Creates and returns a new CBD building instance.
 *
 * This method overrides the build method from the BuildingFactory class
 * to create and return a cloned CBD instance.
 *
 * @return Building* A pointer to the newly created CBD instance.
 */
Building *CBDFactory::build()
{
    return building->clone();
}
