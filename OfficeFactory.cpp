#include "OfficeFactory.h"

OfficeFactory::OfficeFactory()
{
    // Initialize a new Office building instance for future cloning.
    building = new Office();
}

Building *OfficeFactory::build()
{
    /**
     * @brief Creates and returns a new Office building.
     *
     * This method invokes the clone method on the existing Office instance
     * to create a new copy of the Office building. It is part of the
     * Factory Method design pattern.
     *
     * @return Building* A pointer to the newly created Office instance.
     */
    return building->clone();
}
