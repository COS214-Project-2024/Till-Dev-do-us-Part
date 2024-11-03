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
#include "Suburb.h"
#include "Plant.h"
#include "Industrial.h"
#include "IndustrialSite.h"
#include "CBD.h"


class DevelopmentDept : public Department
{

    private:
        int land;
        map<std::string, float> priceList;
        map<std::string, float> buildingAreaList;
        map<std::string, BuildingFactory *> factories;
        vector<Building *> unOccupiedBuildings;
        vector<Residential*> suburbs;
        vector<Commercial*> cbds;
        vector<Industrial *> industrialSites;

    public : 
        DevelopmentDept(float budget);
        ~DevelopmentDept();
        float getPrice(std::string buildingType);
        Building *build(std::string buildingType);
        void addUnoccupiedBuilding(Building* b);
        void DevelopmentDept::removeUnoccupiedBuilding(Building *b);

    };

#endif