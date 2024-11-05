#ifndef DEVELOPMENTDEPT_H
#define DEVELOPMENTDEPT_H

#include <map>
#include <vector>
#include "Building.h"
#include "BuildingFactory.h"
#include "HouseFactory.h"
#include "TownhouseFactory.h"
#include "EstateFactory.h"
#include "ShopFactory.h"
#include "OfficeFactory.h"
#include "MallFactory.h"
#include "FactoryFactory.h"
#include "WarehouseFactory.h"
#include "CBDFactory.h"
#include "SuburbFactory.h"
#include "IndustrialFactory.h"
#include "Department.h"
#include "Suburb.h"
#include "Plant.h"
#include "Industrial.h"
#include "IndustrialSite.h"
#include "CBD.h"

/**
 * @brief Represents the development department responsible for managing
 * building construction and resources.
 *
 * This department handles the construction of various building types, manages
 * unoccupied buildings, and interacts with resource departments.
 */
class DevelopmentDept : public Department
{
private:
    ResourceDepartment *resourceDept;                   ///< Pointer to the resource department for managing resources.
    int land;                                           ///< Amount of land available for development.
    std::map<std::string, float> priceList;             ///< Map storing prices of different building types.
    std::map<std::string, float> buildingAreaList;      ///< Map storing area sizes for different building types.
    std::map<std::string, BuildingFactory *> factories; ///< Map of building factories for different types.
    std::vector<Building *> unOccupiedBuildings;        ///< List of currently unoccupied buildings.
    std::vector<Residential *> suburbs;                 ///< List of suburb objects managed by the department.
    std::vector<Commercial *> cbds;                     ///< List of CBD objects managed by the department.
    std::vector<Industrial *> industrialSites;          ///< List of industrial site objects managed by the department.

public:
    /**
     * @brief Constructs a new Development Department with a specified budget
     * and resource department.
     *
     * @param budget The budget allocated for the development department.
     * @param resourceDept Pointer to the resource department for resource management.
     */
    DevelopmentDept(float budget, ResourceDepartment *resourceDept);

    /**
     * @brief Destroys the Development Department, freeing associated resources.
     */
    ~DevelopmentDept();

    /**
     * @brief Retrieves the price for a specified building type.
     *
     * @param buildingType The type of building for which the price is requested.
     * @return float The price of the specified building type.
     */
    float getPrice(std::string buildingType);

    /**
     * @brief Constructs a building of the specified type.
     *
     * @param buildingType The type of building to construct.
     * @return Building* Pointer to the newly constructed building.
     */
    Building *build(std::string buildingType);

    /**
     * @brief Adds an unoccupied building to the department's list.
     *
     * @param b Pointer to the unoccupied building to add.
     */
    void addUnoccupiedBuilding(Building *b);

    /**
     * @brief Removes a building from the list of unoccupied buildings.
     *
     * @param b Pointer to the building to remove.
     */
    void removeUnoccupiedBuilding(Building *b);
};

#endif
