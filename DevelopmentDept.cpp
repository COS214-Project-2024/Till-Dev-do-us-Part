#include "DevelopmentDept.h"

DevelopmentDept::DevelopmentDept(float budget)
{
    this->budget = budget;
    land = 10000000;

    buildingAreaList["House"] = 500;
    buildingAreaList["Townhouse"] = 180;
    buildingAreaList["Estate"] = 500;
    buildingAreaList["Office"] = 180;
    buildingAreaList["Shop"] = 200;
    buildingAreaList["Mall"] = 1000;
    buildingAreaList["Warehouse"] = 500;
    buildingAreaList["Factory"] = 1200;
    buildingAreaList["Plant"] = 1200;
    buildingAreaList["Park"] = 1200;
    buildingAreaList["Monument"] = 1200;
    buildingAreaList["Cultural Center"] = 1200;
    buildingAreaList["Hospital"] = 1200;
    buildingAreaList["CBD"] = 1200;
    buildingAreaList["Suburb"] = 12000;
    buildingAreaList["Industrial"] = 1200;

    priceList["House"] = 1000;
    priceList["Townhouse"] = 180;
    priceList["Estate"] = 500;
    priceList["Office"] = 180;
    priceList["Shop"] = 200;
    priceList["Mall"] = 1000;
    priceList["Warehouse"] = 500;
    priceList["Factory"] = 1200;
    priceList["Plant"] = 1200;
    priceList["Park"] = 1200;
    priceList["Monument"] = 1200;
    priceList["Cultural Center"] = 1200;
    priceList["Hospital"] = 1200;
    priceList["CBD"] = 1200;
    priceList["Suburb"] = 12000;
    priceList["Industrial"] = 1200;



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
        cout << "second: " << (it)->second;
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

    if(land - buildingAreaList[buildingType] > 0 && budget - priceList[buildingType] > 0){

        land -= buildingAreaList[buildingType];
        budget -= priceList[buildingType];
        map<string, BuildingFactory *>::iterator it = factories.find(buildingType);
        if(it != factories.end())
        {
            BuildingFactory *factory = it->second;
            Building *newBuilding = factory->build();
            if (buildingType == "House" || buildingType == "Townhouse" || buildingType == "Estate"){
                for (vector<Residential*>::iterator it = suburbs.begin(); it != suburbs.end(); it++)
                {
                    if(((Suburb*)(*it))->addBuilding((Residential*)newBuilding)){
                        return newBuilding;
                    }
                }

                Suburb *newSub = new Suburb();
                newSub->addBuilding((Residential *)newBuilding);
                suburbs.push_back(newSub);
                return newBuilding;
            }
            else{
                if (buildingType == "Factory" || buildingType == "Warehouse" || buildingType == "Plant")
                {
                    for (vector<Industrial *>::iterator it = industrialSites.begin(); it != industrialSites.end(); it++)
                    {
                        if (((IndustrialSite *)(*it))->addBuilding((Industrial *)newBuilding))
                        {
                            return newBuilding;
                        }
                    }

                    IndustrialSite *newIndust = new IndustrialSite();
                    newIndust->addBuilding((Industrial *)newBuilding);
                    industrialSites.push_back(newIndust);
                    return newBuilding;
                }
                else{

                    for (vector<Commercial *>::iterator it = cbds.begin(); it != cbds.end(); it++)
                    {
                        if (((CBD *)(*it))->addBuilding((Building *)newBuilding))
                        {
                            return newBuilding;
                        }
                    }

                    CBD *newCBD = new CBD();
                    newCBD->addBuilding((Building *)newBuilding);
                    cbds.push_back(newCBD);
                    return newBuilding;
                }
            }
        }
    }

    return nullptr;
}

void DevelopmentDept::addUnoccupiedBuilding(Building *b)
{
    if(b != nullptr){
        unOccupiedBuildings.push_back(b);
    }
}

void DevelopmentDept::removeUnoccupiedBuilding(Building* b){
    vector<Building *>::iterator first = unOccupiedBuildings.begin();
    vector<Building *>::iterator last = unOccupiedBuildings.end();

    vector<Building *>::iterator it = find(first, last, b);
    if (it != last)
    {
        unOccupiedBuildings.erase(it);
    }
}