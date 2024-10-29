#include "DevelopmentDept.h"

DevelopmentDept::DevelopmentDept(float budget)
{
    this->budget = budget;
    factories["Shop"] = new ShopFactory();
    factories["Office"] = new OfficeFactory();
    factories["Mall"]= new MallFactory();

    // factories["House"]= new HouseFactory();
    // factories["Townhouse"] = new TownhouseFactory();
    // factories["Estate"] = new EstateFactory();
    // factories["Factory"]= new FactoryFactory();
    // factories["Warehouse"]= new WarehouseFactory();
}

bool DevelopmentDept::allocateLand(int landsize)
{
    land = landsize;
}

float DevelopmentDept::getPrice(std::string buildingType)
{
    auto building = priceList.find(buildingType);
    return building->second;
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
    

    map<string,BuildingFactory *>::iterator it = factories.find(buildingType);
    if (it != factories.end())
    {
        BuildingFactory *factory = it->second;

        return factory->build();
    }
    return nullptr;
}