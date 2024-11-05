#include "WarehouseFactory.h"

/**
 * @brief Constructs a WarehouseFactory object.
 *
 * This constructor initializes a new instance of the WarehouseFactory,
 * creating a Warehouse building instance.
 */
WarehouseFactory::WarehouseFactory()
{
    building = new Warehouse();
}

/**
 * @brief Creates and returns a new Warehouse building instance.
 *
 * This method overrides the build method from the BuildingFactory class
 * to create and return a cloned Warehouse instance.
 *
 * @return Building* A pointer to the newly created Warehouse instance.
 */
Building *WarehouseFactory::build()
{
    return building->clone();
}
