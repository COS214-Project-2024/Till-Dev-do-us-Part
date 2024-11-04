#ifndef SHOPFACTORY_H
#define SHOPFACTORY_H

#include "BuildingFactory.h"
#include "Shop.h"

/**
 * @class ShopFactory
 * @brief A factory class for creating Shop building instances.
 *
 * The ShopFactory class is responsible for instantiating new
 * Shop objects using the Factory Method design pattern.
 * It derives from the BuildingFactory base class.
 */
class ShopFactory : public BuildingFactory
{
public:
    /**
     * @brief Constructs a ShopFactory object.
     *
     * Initializes a new instance of the Shop building
     * that will be used for cloning when creating new
     * Shop buildings.
     */
    ShopFactory()
    {
        building = new Shop();
    }

    /**
     * @brief Creates and returns a new Shop building instance.
     *
     * This method overrides the build method from the
     * BuildingFactory class to create a new Shop
     * building by cloning the existing Shop instance.
     *
     * @return Building* A pointer to the newly created
     * Shop instance.
     */
    Building *build()
    {
        return building->clone();
    }
};

#endif
