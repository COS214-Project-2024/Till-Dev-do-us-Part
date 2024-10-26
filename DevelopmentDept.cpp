#include "DevelopmentDept.h"

DevelopmentDept:: DevelopmentDept(float budget)
{
    this->budget=budget;
}
bool DevelopmentDept:: allocateLand(int Landsize)
{
    land=landsize;
}
float DevelopmentDept:: getPrice(std:: string buildingType)
{
    auto building = priceList.find(buildingType);
    return building->getPrice();
}
void DevelopmentDept::addFactory(const std::string& buildingType, BuildingFactory* factory) {
    factories[buildingType] = factory;
}

Building* DevelopmentDept:: build(std:: string buildingType)
{
    auto it = factories.find(buildingType);
    if (it != factories.end()) {
        BuildingFactory* factory = it->second;
        return factory->build(); 
    }
    return nullptr

}