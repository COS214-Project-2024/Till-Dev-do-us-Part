#ifndef WAREHOUSEFACTORY_H
#define WAREHOUSEFACTORY_H

#include "BuildingFactory.h"
#include "Warehouse.h"

/**
 * @brief Factory class for creating Warehouse buildings.
 *
 * The WarehouseFactory class is responsible for creating instances of Warehouse buildings.
 * It inherits from the BuildingFactory class and implements the build method to produce
 * cloned Warehouse objects.
 */
class WarehouseFactory : public BuildingFactory
{

public:
    /**
     * @brief Constructs a WarehouseFactory object.
     *
     * This constructor initializes a new instance of the WarehouseFactory,
     * creating a Warehouse building instance.
     */
    WarehouseFactory();

    /**
     * @brief Creates and returns a new Warehouse building instance.
     *
     * This method overrides the build method from the BuildingFactory class
     * to create and return a cloned Warehouse instance.
     *
     * @return Building* A pointer to the newly created Warehouse instance.
     */
    Building *build();
};

#endif
