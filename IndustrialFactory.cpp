#include "IndustrialFactory.h"

IndustrialFactory::IndustrialFactory()
{
    // Initializes a new instance of the IndustrialSite building.
    building = new IndustrialSite();
}

/**
 * @brief Creates a new IndustrialSite building.
 *
 * This method calls the clone function of the existing
 * IndustrialSite object to create and return a new instance.
 *
 * @return Building* A pointer to the newly created IndustrialSite instance.
*/
Building *IndustrialFactory::build()
{
    return building->clone();
}
