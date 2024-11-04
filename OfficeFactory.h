#ifndef OFFICEFACTORY_H
#define OFFICEFACTORY_H

#include "BuildingFactory.h"
#include "Office.h"

/**
 * @class OfficeFactory
 * @brief A factory class for creating Office building instances.
 *
 * The OfficeFactory class is derived from the BuildingFactory class
 * and implements the build method to create new Office buildings.
 */
class OfficeFactory : public BuildingFactory
{
public:
    /**
     * @brief Constructs an OfficeFactory object.
     *
     * Initializes a new instance of the Office building to be used
     * for cloning when creating new Office buildings.
     */
    OfficeFactory();

    /**
     * @brief Creates and returns a new Office building instance.
     *
     * This method calls the clone method on the Office instance to
     * create a new copy of the Office building. It is part of the
     * Factory Method design pattern.
     *
     * @return Building* A pointer to the newly created Office instance.
     */
    Building *build();
};

#endif
