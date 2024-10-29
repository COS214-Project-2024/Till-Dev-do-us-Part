////hold factory

#ifndef DevelopmentDept_H
#define DevelopmentDept_H
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
#include "Department.h"


class DevelopmentDept : public Department
{

    private:
        int land;
        map<std::string, float> priceList;
        map<std::string, BuildingFactory *> factories;
        vector<Building*> unOccupiedBuildings;

    public : 
        DevelopmentDept(float budget);
        bool allocateLand(int Landsize);
        float getPrice(std::string buildingType);
        void addFactory(const std::string buildingType, BuildingFactory *factory);
        Building *build(std::string buildingType);
        ~DevelopmentDept();
};

#endif
