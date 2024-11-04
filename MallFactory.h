#ifndef MALLFACTORY_H
#define MALLFACTORY_H

#include "BuildingFactory.h"
#include "Mall.h"

/**
 * @class MallFactory
 * @brief A factory class for creating Mall buildings.
 *
 * This class inherits from BuildingFactory and provides functionality
 * to create new instances of Mall buildings.
 */
class MallFactory : public BuildingFactory
{

public:
    /**
     * @brief Constructs a MallFactory object.
     *
     * Initializes a new Mall building instance to be used for
     * creating new Mall objects.
     */
    MallFactory();

    /**
     * @brief Creates and returns a new Mall building.
     *
     * This method creates a new Mall object by invoking the clone method
     * on the existing Mall instance.
     *
     * @return Building* A pointer to the newly created Mall instance.
     */
    Building *build();
};

#endif
