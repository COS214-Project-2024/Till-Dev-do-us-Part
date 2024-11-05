#include "DevelopmentDept.h"

/**
 * @brief Constructs a new Development Department with a specified budget
 * and resource department.
 *
 * Initializes the building area and price lists for various building types.
 *
 * @param budget The budget allocated for the development department.
 * @param r Pointer to the resource department for resource management.
 */
DevelopmentDept::DevelopmentDept(float budget, ResourceDepartment *r)
{
    if (r != nullptr)
    {
        resourceDept = r;
    }
    this->budget = budget;
    land = 10000000; // Initial land available for development.

    // Initialize building area sizes for different types.
    buildingAreaList["House"] = 400;
    buildingAreaList["Townhouse"] = 200;
    buildingAreaList["Estate"] = 1500;
    buildingAreaList["Office"] = 180;
    buildingAreaList["Shop"] = 600;
    buildingAreaList["Mall"] = 12000;
    buildingAreaList["Warehouse"] = 1000;
    buildingAreaList["Factory"] = 1300;
    buildingAreaList["Plant"] = 4000;
    buildingAreaList["Park"] = 600;
    buildingAreaList["Monument"] = 300;
    buildingAreaList["Cultural Center"] = 500;
    buildingAreaList["Hospital"] = 3000;
    buildingAreaList["CBD"] = 50000;
    buildingAreaList["Suburb"] = 50000;
    buildingAreaList["Industrial"] = 60000;

    // Initialize price list for different building types.
    priceList["House"] = 1000;
    priceList["Townhouse"] = 7000;
    priceList["Estate"] = 200000;
    priceList["Office"] = 12000;
    priceList["Shop"] = 180000;
    priceList["Mall"] = 350000;
    priceList["Warehouse"] = 30000;
    priceList["Factory"] = 50000;
    priceList["Plant"] = 100000;
    priceList["Park"] = 30000;
    priceList["Monument"] = 20000;
    priceList["Cultural Center"] = 30000;
    priceList["Hospital"] = 100000;
    priceList["CBD"] = 12000;
    priceList["Suburb"] = 12000;
    priceList["Industrial"] = 12000;

    // Initialize factories for each building type.
    factories["House"] = new HouseFactory();
    factories["Townhouse"] = new TownhouseFactory();
    factories["Estate"] = new EstateFactory();
    factories["Shop"] = new ShopFactory();
    factories["Office"] = new OfficeFactory();
    factories["Mall"] = new MallFactory();
    factories["Factory"] = new FactoryFactory();
    factories["Warehouse"] = new WarehouseFactory();
    factories["CBD"] = new CBDFactory();
    factories["Suburb"] = new SuburbFactory();
    factories["Industrial"] = new IndustrialFactory();
}

/**
 * @brief Destroys the Development Department and frees associated resources.
 */
DevelopmentDept::~DevelopmentDept()
{
    priceList.clear();
    buildingAreaList.clear();

    for (map<string, BuildingFactory *>::iterator it = factories.begin(); it != factories.end(); it++)
    {
        delete (it)->second;
        (it)->second = nullptr;
        // cout << "second: " << (it)->second;
        factories.erase(it->first);
    }

    for (vector<Building *>::iterator it = unOccupiedBuildings.begin(); it != unOccupiedBuildings.end(); it++)
    {
        delete (*it);
        (*it) = nullptr;
        unOccupiedBuildings.erase(it);
    }

    for (vector<Residential *>::iterator it = suburbs.begin(); it != suburbs.end(); it++)
    {
        delete (*it);
        (*it) = nullptr;
        suburbs.erase(it);
    }

    for (vector<Commercial *>::iterator it = cbds.begin(); it != cbds.end(); it++)
    {
        delete (*it);
        (*it) = nullptr;
        cbds.erase(it);
    }

    for (vector<Industrial *>::iterator it = industrialSites.begin(); it != industrialSites.end(); it++)
    {
        delete (*it);
        (*it) = nullptr;
        industrialSites.erase(it);
    }
}

/**
 * @brief Retrieves the price for a specified building type.
 *
 * @param buildingType The type of building for which the price is requested.
 * @return float The price of the specified building type.
 */
float DevelopmentDept::getPrice(std::string buildingType)
{
    auto it = priceList.find(buildingType);
    if (it != priceList.end())
    {
        return it->second; // Return the price if found.
    }
    return 0.0f; // Return 0 if the building type is not found.
}

/**
 * @brief Constructs a building of the specified type.
 *
 * Checks for unoccupied buildings before creating a new one if necessary.
 *
 * @param buildingType The type of building to construct.
 * @return Building* Pointer to the newly constructed building, or nullptr if unable to build.
 */
Building *DevelopmentDept::build(std::string buildingType)
{
    for (vector<Building *>::iterator it = unOccupiedBuildings.begin(); it != unOccupiedBuildings.end(); it++)
    {
        if ((*it)->getType() == buildingType)
        {
            Building *building = (*it);
            unOccupiedBuildings.erase(it);

            if (buildingType == "House" || buildingType == "Townhouse" || buildingType == "Estate")
            {
                for (vector<Residential *>::iterator it = suburbs.begin(); it != suburbs.end(); it++)
                {
                    if (((Suburb *)(*it))->addBuilding((Residential *)building))
                    {
                        building->addResourceDept(resourceDept);
                        return building;
                    }
                }

                Suburb *newSub = new Suburb();
                newSub->addBuilding((Residential *)building);
                suburbs.push_back(newSub);
                building->addResourceDept(resourceDept);

                return building;
            }
            else
            {
                if (buildingType == "Factory" || buildingType == "Warehouse" || buildingType == "Plant")
                {
                    for (vector<Industrial *>::iterator it = industrialSites.begin(); it != industrialSites.end(); it++)
                    {
                        if (((IndustrialSite *)(*it))->addBuilding((Industrial *)building))
                        {
                            building->addResourceDept(resourceDept);
                            return building;
                        }
                    }

                    IndustrialSite *newIndust = new IndustrialSite();
                    newIndust->addBuilding((Industrial *)building);
                    industrialSites.push_back(newIndust);
                    building->addResourceDept(resourceDept);
                    return building;
                }
                else
                {

                    for (vector<Commercial *>::iterator it = cbds.begin(); it != cbds.end(); it++)
                    {
                        if (((CBD *)(*it))->addBuilding((Building *)building))
                        {
                            building->addResourceDept(resourceDept);
                            return building;
                        }
                    }

                    CBD *newCBD = new CBD();
                    newCBD->addBuilding((Building *)building);
                    cbds.push_back(newCBD);
                    building->addResourceDept(resourceDept);
                    return building;
                }
            }
        }
    }

    if (land - buildingAreaList[buildingType] > 0 && budget - priceList[buildingType] > 0)
    {

        land -= buildingAreaList[buildingType];
        budget -= priceList[buildingType];
        map<string, BuildingFactory *>::iterator it = factories.find(buildingType);
        if (it != factories.end())
        {
            BuildingFactory *factory = it->second;
            Building *newBuilding = factory->build();
            if (buildingType == "House" || buildingType == "Townhouse" || buildingType == "Estate")
            {
                for (vector<Residential *>::iterator it = suburbs.begin(); it != suburbs.end(); it++)
                {
                    if (((Suburb *)(*it))->addBuilding((Residential *)newBuilding))
                    {
                        newBuilding->addResourceDept(resourceDept);
                        return newBuilding;
                    }
                }

                Suburb *newSub = new Suburb();
                newSub->addBuilding((Residential *)newBuilding);
                suburbs.push_back(newSub);
                newBuilding->addResourceDept(resourceDept);
                return newBuilding;
            }
            else
            {
                if (buildingType == "Factory" || buildingType == "Warehouse" || buildingType == "Plant")
                {
                    for (vector<Industrial *>::iterator it = industrialSites.begin(); it != industrialSites.end(); it++)
                    {
                        if (((IndustrialSite *)(*it))->addBuilding((Industrial *)newBuilding))
                        {
                            newBuilding->addResourceDept(resourceDept);
                            return newBuilding;
                        }
                    }

                    IndustrialSite *newIndust = new IndustrialSite();
                    newIndust->addBuilding((Industrial *)newBuilding);
                    industrialSites.push_back(newIndust);
                    newBuilding->addResourceDept(resourceDept);
                    return newBuilding;
                }
                else
                {

                    for (vector<Commercial *>::iterator it = cbds.begin(); it != cbds.end(); it++)
                    {
                        if (((CBD *)(*it))->addBuilding((Building *)newBuilding))
                        {
                            newBuilding->addResourceDept(resourceDept);
                            return newBuilding;
                        }
                    }

                    CBD *newCBD = new CBD();
                    newCBD->addBuilding((Building *)newBuilding);
                    cbds.push_back(newCBD);
                    newBuilding->addResourceDept(resourceDept);
                    return newBuilding;
                }
            }
        }
    }

    return nullptr;
}

/**
 * @brief Adds an unoccupied building to the list of unoccupied buildings.
 *
 * @param b Pointer to the building to be added.
 */
void DevelopmentDept::addUnoccupiedBuilding(Building *b)
{
    if (b != nullptr)
    {
        unOccupiedBuildings.push_back(b); // Add the building to the list.
    }
}

/**
 * @brief Removes a specified unoccupied building from the list.
 *
 * @param b Pointer to the building to be removed.
 */
void DevelopmentDept::removeUnoccupiedBuilding(Building *b)
{
    vector<Building *>::iterator first = unOccupiedBuildings.begin();
    vector<Building *>::iterator last = unOccupiedBuildings.end();

    vector<Building *>::iterator it = find(first, last, b);
    if (it != last)
    {
        unOccupiedBuildings.erase(it);
    }
}
