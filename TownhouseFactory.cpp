#include "TownhouseFactory.h"

/**
 * @brief Constructor for TownhouseFactory.
 *
 * Initializes a new instance of the TownhouseFactory class,
 * creating a new Townhouse building instance.
 */
TownhouseFactory::TownhouseFactory()
{
    building = new Townhouse();
}

/**
 * @brief Creates and returns a new Townhouse building instance.
 *
 * This method overrides the build method from the
 * BuildingFactory class to create a new Townhouse
 * building by cloning the existing Townhouse instance.
 *
 * @return Building* A pointer to the newly created
 * Townhouse instance.
 */
Building *TownhouseFactory::build()
{
    return building->clone();
}
