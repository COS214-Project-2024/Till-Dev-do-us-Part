#include "DevelopmentDept.h"

DevelopmentDept::DevelopmentDept(float budget)
{
    this->budget = budget;

    buildingAreaList["House"] = 200;
    buildingAreaList["Townhouse"] = 180;
    buildingAreaList["Estate"] = 500;
    buildingAreaList["Office"] = 180;
    buildingAreaList["Shop"] = 200;
    buildingAreaList["Mall"] = 1000;
    buildingAreaList["Warehouse"] = 500;
    buildingAreaList["Factory"] = 1200;

    factories["Shop"] = new ShopFactory();
    factories["Office"] = new OfficeFactory();
    factories["Mall"]= new MallFactory();

    // factories["House"]= new HouseFactory();
    // factories["Townhouse"] = new TownhouseFactory();
    // factories["Estate"] = new EstateFactory();
    // factories["Factory"]= new FactoryFactory();
    // factories["Warehouse"]= new WarehouseFactory();
}

DevelopmentDept::~DevelopmentDept()
{
    priceList.clear();
    buildingAreaList.clear();

    for (map<string, BuildingFactory *>::iterator it = factories.begin(); it != factories.end(); it++)
    {
        delete (it)->second;
        (it)->second = nullptr;
        factories.erase(it->first);
    }
    
    for (vector<Building *>::iterator it = unOccupiedBuildings.begin(); it != unOccupiedBuildings.end(); it++)
    {
        delete (*it);
        (*it) = nullptr;
        unOccupiedBuildings.erase(it);
    }
}

float DevelopmentDept::getPrice(std::string buildingType)
{
    float price = priceList.find(buildingType)->second;
    return price;
}

void DevelopmentDept::addFactory(const std::string buildingType, BuildingFactory *factory)
{
    factories[buildingType] = factory;
}

Building* DevelopmentDept::build(std::string buildingType)
{
    for (vector<Building*>::iterator it = unOccupiedBuildings.begin(); it != unOccupiedBuildings.end(); it++)
    {
        if((*it)->getType() == buildingType){
            Building* building = (*it);
            unOccupiedBuildings.erase(it);
            return building; //citizen will have to add themselves to the building
        }
    }

    if(land - buildingAreaList[buildingType] > 0){
        land -= buildingAreaList[buildingType];
        map<string, BuildingFactory *>::iterator it = factories.find(buildingType);
        if (it != factories.end())
        {
            BuildingFactory *factory = it->second;
            return factory->build();
        }
    }

    return nullptr;
}