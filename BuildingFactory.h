#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

class Building; // Forward declaration

/**
 * @brief Abstract base class for building factories.
 *
 * The BuildingFactory class provides an interface for creating Building objects.
 * Derived classes must implement the build method to create specific types of buildings.
 */
class BuildingFactory
{
protected:
    Building *building; ///< Pointer to the building being created.

public:
    // BuildingFactory(); // Uncomment if a constructor is needed

    /**
     * @brief Pure virtual method to create a Building object.
     *
     * This method must be implemented by derived classes to create a specific
     * type of building.
     *
     * @return Building* A pointer to the newly created Building instance.
     */
    virtual Building *build() = 0;

    /**
     * @brief Destructor for BuildingFactory.
     *
     * Cleans up the allocated building object if it exists.
     */
    virtual ~BuildingFactory()
    {
        delete building;
        building = nullptr;
    }
};

#endif
