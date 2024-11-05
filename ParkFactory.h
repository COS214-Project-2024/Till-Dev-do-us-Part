#ifndef PARKFACTORY_H
#define PARKFACTORY_H

#include "BuildingFactory.h"
#include "Park.h"

/**
 * @class ParkFactory
 * @brief A factory class for creating Park building instances.
 *
 * The ParkFactory class is responsible for instantiating new
 * Park objects using the Factory Method design pattern.
 * It derives from the BuildingFactory base class.
 */
class ParkFactory : public BuildingFactory
{
public:
    /**
     * @brief Constructs a ParkFactory object.
     *
     * Initializes a new instance of the Park building
     * that will be used for cloning when creating new
     * Park buildings.
     */
    ParkFactory();

    /**
     * @brief Creates and returns a new Park building instance.
     *
     * This method overrides the build method from the
     * BuildingFactory class to create a new Park
     * building by cloning the existing Park instance.
     *
     * @return Building* A pointer to the newly created
     * Park instance.
     */
    Building *build();
};

#endif
