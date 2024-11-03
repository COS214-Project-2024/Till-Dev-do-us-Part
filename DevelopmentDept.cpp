#include "DevelopmentDept.h"

DevelopmentDept::DevelopmentDept(float budget)
{
    this->budget = budget;
    land = 10000000;

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



    factories["House"]= new HouseFactory();
    factories["Townhouse"] = new TownhouseFactory();
    factories["Estate"] = new EstateFactory();
    factories["Shop"] = new ShopFactory();
    factories["Office"] = new OfficeFactory();
    factories["Mall"]= new MallFactory();
    factories["Factory"]= new FactoryFactory();
    factories["Warehouse"]= new WarehouseFactory();
    factories["Monument"]= new MonumentFactory();
    factories["Cultural Center"]= new CulturalFactory();
    factories["Hospital"]= new HospitalFactory();
    factories["CBD"]= new CBDFactory();
    factories["Suburb"]= new SuburbFactory();
    factories["Industrial"]= new IndustrialFactory();
}

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

    for(vector<Residential*>::iterator it=suburbs.begin(); it != suburbs.end();it++){
        delete (*it);
        (*it) = nullptr;
        suburbs.erase(it);
    }
    
    for(vector<Commercial*>::iterator it=cbds.begin(); it != cbds.end();it++){
        delete (*it);
        (*it) = nullptr;
        cbds.erase(it);
    }
    
    for(vector<Industrial*>::iterator it=industrialSites.begin(); it != industrialSites.end();it++){
        delete (*it);
        (*it) = nullptr;
        industrialSites.erase(it);
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

            if (buildingType == "House" || buildingType == "Townhouse" || buildingType == "Estate"){
                for (vector<Residential*>::iterator it = suburbs.begin(); it != suburbs.end(); it++)
                {
                    if(((Suburb*)(*it))->addBuilding((Residential*)building)){
                        return building;
                    }
                }

                Suburb *newSub = new Suburb();
                newSub->addBuilding((Residential *)building);
                suburbs.push_back(newSub);
                return building;
            }
            else{
                if (buildingType == "Factory" || buildingType == "Warehouse" || buildingType == "Plant")
                {
                    for (vector<Industrial *>::iterator it = industrialSites.begin(); it != industrialSites.end(); it++)
                    {
                        if (((IndustrialSite *)(*it))->addBuilding((Industrial *)building))
                        {
                            return building;
                        }
                    }

                    IndustrialSite *newIndust = new IndustrialSite();
                    newIndust->addBuilding((Industrial *)building);
                    industrialSites.push_back(newIndust);
                    return building;
                }
                else{

                    for (vector<Commercial *>::iterator it = cbds.begin(); it != cbds.end(); it++)
                    {
                        if (((CBD *)(*it))->addBuilding((Building *)building))
                        {
                            return building;
                        }
                    }

                    CBD *newCBD = new CBD();
                    newCBD->addBuilding((Building *)building);
                    cbds.push_back(newCBD);
                    return building;
                }
            }
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