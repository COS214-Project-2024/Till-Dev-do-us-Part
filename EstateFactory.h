#ifndef ESTATEFACTORY_H
#define ESTATEFACTORY_H

#include "BuildingFactory.h"
#include "Estate.h"

/**
 * @brief A factory class for creating Estate buildings.
 *
 * The EstateFactory is responsible for creating instances of the Estate class.
 * It follows the Factory Method design pattern, enabling the creation of building
 * objects while allowing for customization of the construction process.
 */
class EstateFactory : public BuildingFactory
{

public:
    /**
     * @brief Constructs an EstateFactory object.
     *
     * Initializes a new instance of the Estate building.
     */
    EstateFactory();

    /**
     * @brief Creates and returns a clone of the Estate object.
     *
     * This method produces a new instance of an Estate by cloning the pre-defined
     * Estate object in the factory.
     *
     * @return Building* A pointer to a new instance of Estate.
     */
    Building *build();
};

#endif
