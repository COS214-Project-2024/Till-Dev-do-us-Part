#ifndef HOUSEFACTORY_H
#define HOUSEFACTORY_H

#include "BuildingFactory.h"
#include "House.h"

/**
 * @brief Factory class for creating House buildings.
 *
 * The HouseFactory is responsible for instantiating House objects
 * using the factory method design pattern. It provides a way to
 * create House objects without specifying the exact class of
 * object that will be created.
 */
class HouseFactory : public BuildingFactory
{
public:
    /**
     * @brief Constructs a HouseFactory object.
     *
     * This constructor initializes a new instance of the House building.
     */
    HouseFactory();

    /**
     * @brief Creates and returns a clone of the House object.
     *
     * This method creates a new instance of the House building by calling
     * the clone method on the existing House object.
     *
     * @return Building* A pointer to a new instance of House.
     */
    Building *build();
};

#endif
