#ifndef IndustrialFactory_H
#define IndustrialFactory_H

#include "BuildingFactory.h"
#include "IndustrialSite.h"

/**
 * @class IndustrialFactory
 * @brief A factory class for creating IndustrialSite buildings.
 *
 * This class inherits from BuildingFactory and implements the method
 * to create new instances of IndustrialSite.
 */
class IndustrialFactory : public BuildingFactory
{
public:
    /**
     * @brief Constructs an IndustrialFactory object.
     *
     * This constructor initializes a new IndustrialSite building.
     */
    IndustrialFactory();

    /**
     * @brief Creates and returns a new IndustrialSite building.
     *
     * This method uses the clone method of the existing IndustrialSite
     * instance to create a new building object.
     *
     * @return Building* A pointer to the newly created IndustrialSite instance.
     */
    Building *build();
};

#endif
